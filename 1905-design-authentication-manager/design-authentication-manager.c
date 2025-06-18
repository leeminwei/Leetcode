#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char* token;
    int time;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct AuthenticationManager{
    int limit;
    struct Node* head;
    struct Node* tail;
}AuthenticationManager;


AuthenticationManager* authenticationManagerCreate(int timeToLive) {
    AuthenticationManager* new = (AuthenticationManager*)malloc(sizeof(AuthenticationManager));
    new->head = NULL;
    new->tail = NULL;
    new->limit = timeToLive;
    return new;
}

void authenticationManagerGenerate(AuthenticationManager* obj, char* tokenId, int currentTime) {
    //如果有重複的token，更新時間就好(避免重複的token)
    Node* cur = obj->head;
    while (cur != NULL) {
        if (strcmp(cur->token, tokenId) == 0) {
            cur->time = currentTime + (obj->limit);
            return;
        }
        cur = cur->next;
    }

    //如果雙向串列是空的
    if (obj->head == NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->token = (char*)malloc((strlen(tokenId)+1)*sizeof(char));
        strcpy(newnode->token, tokenId);
        newnode->time = currentTime + (obj->limit);
        newnode->next = NULL;
        newnode->prev = NULL;
        obj->head = newnode;
        obj->tail = newnode;
    }
    else {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->token = (char*)malloc((strlen(tokenId)+1)*sizeof(char));
        strcpy(newnode->token, tokenId);
        newnode->time = currentTime + (obj->limit);
        newnode->next = NULL;
        newnode->prev = obj->tail;
        obj->tail->next = newnode;
        obj->tail = newnode;
    }
}

void authenticationManagerRenew(AuthenticationManager* obj, char* tokenId, int currentTime) {
    //如果鍊表是空的
    if (obj->head == NULL) {
        return;
    }
    
    //如果鍊表不是空的
    Node* cur = obj->head;
    while (cur != NULL) {
        //找到一樣的token
        if (strcmp(cur->token, tokenId) == 0) {
            //確認是否過期
            if (cur->time > currentTime) {
                cur->time = currentTime + (obj->limit);
                return;
            }
        }
        cur = cur->next;
    }
}

int authenticationManagerCountUnexpiredTokens(AuthenticationManager* obj, int currentTime) {
    int count = 0;
    Node* cur = obj->head;
    while (cur != NULL) {
        if (cur->time > currentTime) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}

void authenticationManagerFree(AuthenticationManager* obj) {
    Node* cur = obj->head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur->token);
        free(cur);
        cur = next;
    }
    free(obj);
}

/**
 * Your AuthenticationManager struct will be instantiated and called as such:
 * AuthenticationManager* obj = authenticationManagerCreate(timeToLive);
 * authenticationManagerGenerate(obj, tokenId, currentTime);
 
 * authenticationManagerRenew(obj, tokenId, currentTime);
 
 * int param_3 = authenticationManagerCountUnexpiredTokens(obj, currentTime);
 
 * authenticationManagerFree(obj);
*/