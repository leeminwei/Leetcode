/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode* current = head;
    int count = 0;
    while(current!=NULL){
        count = count*2 + current->val;
        current = current->next;
    }
    return count;
}