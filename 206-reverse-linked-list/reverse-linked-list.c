/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL||head->next==NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* future = current->next;
    while(future!=NULL){
        current->next = prev;
        prev = current;
        current = future;
        future = future->next;
    }
    current->next = prev;
    return current;
}
/*
if(head==NULL) return NULL;
    struct ListNode* current = head;
    struct ListNode* previous = NULL;
    struct ListNode* step = head->next;
    while(step!=NULL){
      current->next = previous;
      previous = current;
      current = step;
      step = step -> next; 
    }
    current->next = previous;
    return current;
*/