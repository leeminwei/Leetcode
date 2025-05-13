/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL) return NULL;
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    struct ListNode* dummy = tail;
    struct ListNode* current = head;
    while(current!=NULL){
        if(tail->val!=current->val){
            tail->next = current;
            tail = tail->next;
            current = current->next;
        }
        else{
            current = current->next;
        }
    }
    tail->next = NULL;
    return dummy->next;
}
/*
struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* tail = dummy;
    struct ListNode* current = head;
    while(current!=NULL){
        if(current->next!=NULL && current->val == current->next->val){
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = current->val;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            while (current->next != NULL && current->val == current->next->val) {
                current = current->next;
            }
            current = current->next;
        }
        else{
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = current->val;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            current = current->next;
        } 
    }
    return dummy->next;
*/
