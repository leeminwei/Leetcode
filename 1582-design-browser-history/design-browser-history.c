#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char* page;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct {
    struct Node* head;
    struct Node* tail;
    struct Node* cur;
    int size;
}BrowserHistory;

Node* createNode(char* name){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->page = (char*)malloc(strlen(name)+1);
    strcpy(newnode->page, name);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    Node* newnode = createNode(homepage);
    BrowserHistory* DLL = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    DLL->head = newnode;
    DLL->tail = newnode;
    DLL->cur = newnode;
    DLL->size = 1;
    return DLL;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    Node* newnode = createNode(url);
    //如果歷史紀錄只有一頁
    if (obj->size == 1) {
        newnode->prev = obj->tail;
        obj->tail->next = newnode;
        obj->tail = newnode;
        obj->cur = newnode; 
        obj->size++;
    }
    //如果現在頁面剛好是在tail
    else if (obj->cur == obj->tail) {
        newnode->prev = obj->tail;
        obj->tail->next = newnode;
        obj->tail = newnode;
        obj->cur = newnode; 
        obj->size++;
    }
    else{
        newnode->prev = obj->cur;
        Node* temp = obj->cur->next;
        while (temp != NULL) {
            Node* toRemove = temp;
            temp = temp->next;
            free(toRemove->page);
            free(toRemove);
            obj->size--;
        }
        obj->cur->next = newnode;
        obj->cur = newnode;
        obj->tail = newnode;
        obj->size++;
    }
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (obj->cur->prev != NULL && steps > 0) {
        obj->cur = obj->cur->prev;
        steps--;
    }
    return obj->cur->page;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (obj->cur->next != NULL && steps > 0) {
        obj->cur = obj->cur->next;
        steps--;
    }
    return obj->cur->page;
}

void browserHistoryFree(BrowserHistory* obj) {
    while (obj->head != NULL) {
        Node* toRemove = obj->head;
        obj->head = obj->head->next;
        free(toRemove->page);
        free(toRemove); 
    }
    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/