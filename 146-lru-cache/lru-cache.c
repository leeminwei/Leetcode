#include <stdio.h>
#define MAX_SIZE 1009
typedef struct Node{
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
}ListNode;

typedef struct HashNode{
    int key;
    ListNode* node;
    struct HashNode* next;
}HashNode;

typedef struct LRUCache{
    int capacity;
    int currentSize;
    ListNode* head;
    ListNode* tail;
    HashNode* hashTable[MAX_SIZE];
}LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* newLRU = (LRUCache*)malloc(sizeof(LRUCache));
    newLRU->capacity = capacity;
    newLRU->currentSize = 0;
    newLRU->head = NULL;
    newLRU->tail = NULL;
    for (int i = 0; i < MAX_SIZE; i++) 
        newLRU->hashTable[i] = NULL;
    return newLRU;
}

int hashFunction(int key) {
    return key % MAX_SIZE;
}

void removeFromHashTable(LRUCache* obj, int key) {
    int hashIndex = hashFunction(key);
    HashNode* current = obj->hashTable[hashIndex];
    HashNode* prev = NULL;
    
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                obj->hashTable[hashIndex] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void moveToHead(LRUCache* obj, ListNode* node) {
    if (node == obj->head) {
        return;
    }
    else if (node == obj->tail) {
        obj->tail = node->prev;
        obj->tail->next = NULL;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    obj->head->prev = node;
    node->next = obj->head;
    node->prev = NULL;
    obj->head = node;
    return;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    int hashIndex = hashFunction(key);
    HashNode* current = obj->hashTable[hashIndex];
    HashNode* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            current->node->value = value;
            moveToHead(obj, current->node);
            return;
        }
        prev = current;
        current = current->next;
    }
    HashNode* newHashNode = (HashNode*)malloc(sizeof(HashNode));
    ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
    newHashNode->key = key;
    newHashNode->node = newListNode;
    if (prev == NULL) {
        obj->hashTable[hashIndex] = newHashNode;
    } else {
        prev->next = newHashNode;
    }
    newHashNode->next = NULL;
    newListNode->key = key;
    newListNode->value = value;
    newListNode->prev = NULL;
    newListNode->next = NULL;
    
    if (obj->currentSize == obj->capacity) {
        ListNode* lastNode = obj->tail;
        removeFromHashTable(obj, lastNode->key);
        if (obj->capacity == 1) {
            obj->head = NULL;
            obj->tail = NULL;
        } else {
            obj->tail = lastNode->prev;
            obj->tail->next = NULL;
        }
        free(lastNode);
        obj->currentSize--;
    }
    if (obj->currentSize == 0) {
        obj->head = newListNode;
        obj->tail = newListNode;
    } else {
        obj->head->prev = newListNode;
        newListNode->next = obj->head;
        obj->head = newListNode;
    }
    obj->currentSize++;
    return;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int hashIndex = hashFunction(key);
    HashNode* current = obj->hashTable[hashIndex];
    while (current != NULL) {
        if (current->key == key) {
            moveToHead(obj, current->node);
            return current->node->value;
        }
        current = current->next;
    }
    return -1;
}

void lRUCacheFree(LRUCache* obj) {
    for (int i = 0; i < MAX_SIZE; i++) {
        HashNode* current = obj->hashTable[i];
        while (current != NULL) {
            HashNode* next = current->next;
            free(current);
            current = next;
        }
    }
    ListNode* current = obj->head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    free(obj);
    return;
}