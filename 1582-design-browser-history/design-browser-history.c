#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char* page;
    struct Node* next;
    struct Node* prev;
}Node;


typedef struct BrowserHistory{
    struct Node* head;
    struct Node* tail;
    struct Node* current;
    int size;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char* homepage) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->page = (char*)malloc(strlen(homepage)+1);
    strcpy(newnode->page, homepage);
    newnode->next = NULL;
    newnode->prev = NULL;
    BrowserHistory* newbrowser = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    newbrowser->head = newnode;
    newbrowser->tail = newnode;
    newbrowser->current = newnode;
    newbrowser->size = 1;
    return newbrowser;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    //如果目前瀏覽歷史只有homepage
    if (obj->size == 1) {
        Node* newbrowser = (Node*)malloc(sizeof(Node));
        newbrowser->page = (char*)malloc(strlen(url)+1);
        strcpy(newbrowser->page, url);
        newbrowser->next = NULL;
        newbrowser->prev = obj->head;
        obj->head->next = newbrowser;
        obj->tail = newbrowser;
        obj->current = newbrowser;
        obj->size++;
    }
    else if (obj->current == obj->tail) {
        Node* newbrowser = (Node*)malloc(sizeof(Node));
        newbrowser->page = (char*)malloc(strlen(url)+1);
        strcpy(newbrowser->page, url);
        newbrowser->next = NULL;
        newbrowser->prev = obj->current;
        obj->current->next = newbrowser;
        obj->current = newbrowser;
        obj->tail = newbrowser;
        obj->size++;
    }
    else {
        Node* newbrowser = (Node*)malloc(sizeof(Node));
        newbrowser->page = (char*)malloc(strlen(url)+1);
        strcpy(newbrowser->page, url);
        newbrowser->next = NULL;
        newbrowser->prev = obj->current;
        Node* temp = obj->current->next;
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp->page);
            free(temp);
            temp = next;
            obj->size--;
        }
        obj->current->next = NULL;
        obj->current->next = newbrowser;
        obj->current = newbrowser;
        obj->tail = newbrowser;
        obj->size++; 
    }
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    //如果瀏覽歷史只有homepage
    if (obj->size == 1) {
        return obj->head->page;
    }
    while (steps > 0 && obj->current->prev != NULL) {
        obj->current = obj->current->prev;
        steps--;
    }
    return obj->current->page;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps > 0 && obj->current->next != NULL) {
        obj->current = obj->current->next;
        steps--;
    }
    return obj->current->page;
}

void browserHistoryFree(BrowserHistory* obj) {
    Node* cur = obj->head;
    while (cur != NULL) {
        Node* next = cur->next;  // 提前存下個位置，否則 cur 被 free 後不能再訪問 cur->next
        free(cur->page);         // 先釋放 malloc 出來的字串記憶體
        free(cur);               // 再釋放節點本身
        cur = next;              // 移動到下一個節點
    }
    free(obj); // 最後釋放 BrowserHistory 本體
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/