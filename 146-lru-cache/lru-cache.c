#include <stdio.h>
#define MAX_SIZE 1009 //設太小可能還是O(n)

typedef struct Node{
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct hash{
    int key;
    struct Node* node;
    struct hash* next;
}hash;

typedef struct LRUCache{
    struct Node* head;
    struct Node* tail;
    int capacity;
    int size;
    hash* hashTable[MAX_SIZE];
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* LRU = (LRUCache*)malloc(sizeof(LRUCache));
    LRU->head = NULL;
    LRU->tail = NULL;
    LRU->capacity = capacity;
    LRU->size = 0;
    for (int i=0 ; i<MAX_SIZE ; i++) {
        LRU->hashTable[i] = NULL;
    }
    return LRU;
}

int hashfunction(int key){
    return key % MAX_SIZE;
}

void movetoHead(LRUCache* obj, Node* node){
    //如果node是head
    if (node == obj->head) return;
    //如果node是中間節點
    if (node->prev !=NULL && node->next!=NULL) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = NULL;
        node->next = NULL;
    }
    //如果node是tail
    else if (node == obj->tail) {
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
        node->prev = NULL;
        node->next = NULL;
    }
    //把node移到head的位置
    node->next = obj->head;
    obj->head->prev = node;
    obj->head = node;
    return;
}

void InserttoHead(LRUCache* obj, Node* node){
    //因為放在remove之後，所以還是要考慮LRU為空的狀況
    if (obj->head == NULL) {
        obj->head = obj->tail = node;
    } else {
        node->next = obj->head;
        obj->head->prev = node;
        obj->head = node;
    }
    obj->size++;
}

void removeTail(LRUCache* obj){
    Node* toRemove = obj->tail;
    if (obj->tail == obj->head) {
        obj->head = NULL;
        obj->tail = NULL;
    } else {
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
    }
    free(toRemove);
    obj->size--;
}

void removefromHash(LRUCache* obj, int key){
    int hashindex = hashfunction(key);
    hash* cur = obj->hashTable[hashindex];
    hash* prev = NULL;
    while (cur != NULL) {
        if (cur->key == key) {
            if (prev == NULL) {
                obj->hashTable[hashindex] = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int lRUCacheGet(LRUCache* obj, int key) {
    int hashindex = hashfunction(key);
    hash* cur = obj->hashTable[hashindex];
    while (cur != NULL) {
        if (cur->key == key) {
            movetoHead(obj, cur->node);
            return cur->node->value;
        }
        cur = cur->next;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    //如果LRU是空的
    if (obj->head == NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->key = key;
        newnode->value = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        obj->head = newnode;
        obj->tail = newnode;
        obj->size++;
        int hashindex = hashfunction(key);
        hash* newhashnode = (hash*)malloc(sizeof(hash));
        newhashnode->key = key;
        newhashnode->node = newnode;
        newhashnode->next = NULL;
        obj->hashTable[hashindex] = newhashnode;
        return;
    }
    //如果LRU不是空的
    int hashindex = hashfunction(key);
    hash* cur = obj->hashTable[hashindex];
    while (cur != NULL) {
        //且有重複key出現，那就只需要更新value;
        if (cur->key == key) {
            cur->node->value = value;
            movetoHead(obj, cur->node);
            return;
        }
        cur = cur->next;
    }
    //如果沒有重複key出現
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (obj->size == obj->capacity) {
        removefromHash(obj, obj->tail->key);
        removeTail(obj);
        InserttoHead(obj, newnode);
    }
    else{
        InserttoHead(obj, newnode);
    }
    hash* newhashnode = (hash*)malloc(sizeof(hash));
    newhashnode->key = key;
    newhashnode->node = newnode;
    newhashnode->next = obj->hashTable[hashindex];
    obj->hashTable[hashindex] = newhashnode;
}

void lRUCacheFree(LRUCache* obj) {
    for (int i = 0; i < MAX_SIZE; i++) {
        hash* current = obj->hashTable[i];
        while (current != NULL) {
            hash* next = current->next;
            free(current);
            current = next;
        }
    }
    Node* current = obj->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(obj);
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/