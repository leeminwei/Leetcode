/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    while(current!=NULL){
        if(current->next != NULL && current->val == current->next->val){
            current->next = current->next->next;
        }
        else{
            printf("%d",current->val);
            current = current->next;
        }
    }
    return head;
}