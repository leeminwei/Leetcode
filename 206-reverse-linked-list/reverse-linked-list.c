/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
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
}