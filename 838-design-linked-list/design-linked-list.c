#include <stdio.h>

typedef struct listnode{
    int val;
    struct listnode* prev;
    struct listnode* next;
}listnode;

typedef struct {
    struct listnode* head;
    struct listnode* tail;
    int size;
} MyLinkedList;

listnode* createnode(int val){
    listnode* newnode = (listnode*)malloc(sizeof(listnode));
    newnode->val = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* newlist = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newlist->head = NULL;
    newlist->tail = NULL;
    newlist->size = 0;
    return newlist;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (obj->size == 0 || index >= obj->size) {
        return -1;
    }
    listnode* cur = obj->head;
    for (int i=0 ; i<index ; i++) {
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    listnode* newnode = createnode(val);
    if (obj->size == 0) {
        obj->head = newnode;
        obj->tail = newnode;
        obj->size++;
        return;
    }
    
    newnode->next = obj->head;
    obj->head->prev = newnode;
    obj->head = newnode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    listnode* newnode = createnode(val);
    if (obj->size == 0) {
        obj->head = newnode;
        obj->tail = newnode;
        obj->size++;
        return;
    }
    newnode->prev = obj->tail;
    obj->tail->next = newnode;
    obj->tail = newnode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    }
    else if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    else{
        if (index == 0) {
            myLinkedListAddAtHead(obj, val);
            return;
        }
        listnode* cur = obj->head;
        for (int i=0 ; i<index ; i++) {
            cur = cur->next;
        }
        listnode* newnode = createnode(val);
        newnode->next = cur;
        newnode->prev = cur->prev;
        cur->prev = newnode;
        newnode->prev->next = newnode;
        obj->size++;
    }
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index >= obj->size) {
        return;
    }
    if (index == 0 && obj->size == 1) {
        listnode* toRemove = obj->head;
        obj->head = NULL;
        obj->tail = NULL;
        obj->size = 0;
        free(toRemove);
        return;
    }
    if (index == 0 && obj->size > 1) {
        listnode* toRemove = obj->head;
        obj->head = obj->head->next;
        obj->head->prev = NULL;
        toRemove->next = NULL;
        free(toRemove);
        obj->size--;
        return;
    }
    else if (index == obj->size-1) {
        listnode* toRemove = obj->tail;
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
        toRemove->prev = NULL;
        free(toRemove);
        obj->size--;
        return;
    }
    else{
        listnode* cur = obj->head;
        for (int i=0 ; i<index ; i++) {
            cur = cur->next;
        }
        listnode* toRemove = cur;
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        cur->prev = NULL;
        cur->next = NULL;
        free(toRemove);
        obj->size--;
        return;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    listnode* cur = obj->head;
    while (cur != NULL) {
        listnode* toRemove = cur;
        cur = cur->next;
        if (cur != NULL)
            cur->prev = NULL;
        toRemove->next = NULL;
        free(toRemove);
        obj->size--;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/