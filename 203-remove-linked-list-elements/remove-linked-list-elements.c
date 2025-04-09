/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = NULL;
    struct ListNode* tail = newHead;
    struct ListNode* current = head;
    while(current!= NULL){
        if(current->val != val){
            tail->next = current;
            tail = tail->next;
        }
        current = current->next;
    }
    tail->next = NULL;
    //struct ListNode* result = newHead->next;
    //free(newHead); 
    return newHead->next;
}