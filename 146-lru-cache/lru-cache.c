#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LRUCache {
    int capacity;
    int currentSize;
    Node* head;
    Node* tail;
    Node** hashmap;  // Hash map: key -> Node*
} LRUCache;

int hash(int key) {
    return key % HASH_SIZE;
}

// 建立新的節點
Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// 移動一個節點到尾端（最近使用）
void moveToTail(LRUCache* obj, Node* node) {
    if (node == obj->tail) return;

    // 脫離目前位置
    if (node->prev) node->prev->next = node->next;
    else obj->head = node->next;

    if (node->next) node->next->prev = node->prev;
    else obj->tail = node->prev;

    // 加到尾端
    node->prev = obj->tail;
    node->next = NULL;
    if (obj->tail) obj->tail->next = node;
    obj->tail = node;
}

// 刪除頭節點（最久未使用）
void removeHead(LRUCache* obj) {
    if (!obj->head) return;

    Node* toRemove = obj->head;
    int h = hash(toRemove->key);
    obj->head = toRemove->next;
    if (obj->head) obj->head->prev = NULL;
    else obj->tail = NULL;

    obj->hashmap[h] = NULL;
    free(toRemove);
    obj->currentSize--;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->currentSize = 0;
    obj->head = NULL;
    obj->tail = NULL;
    obj->hashmap = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int h = hash(key);
    Node* node = obj->hashmap[h];
    if (!node) return -1;

    moveToTail(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->capacity == 0) return;

    int h = hash(key);
    Node* node = obj->hashmap[h];

    if (node) {
        node->value = value;
        moveToTail(obj, node);
    } else {
        Node* newNode = createNode(key, value);
        obj->hashmap[h] = newNode;

        // 插入尾端
        newNode->prev = obj->tail;
        newNode->next = NULL;
        if (obj->tail) obj->tail->next = newNode;
        obj->tail = newNode;
        if (!obj->head) obj->head = newNode;

        obj->currentSize++;

        // 超出容量 → 移除最舊節點
        if (obj->currentSize > obj->capacity) {
            removeHead(obj);
        }
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* cur = obj->head;
    while (cur) {
        Node* toFree = cur;
        cur = cur->next;
        free(toFree);
    }
    free(obj->hashmap);
    free(obj);
}
