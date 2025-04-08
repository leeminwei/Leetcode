/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *current = headA;
    struct ListNode *current2 = headB;
    while(current!=NULL){
        while(current2!=NULL){
            if(current == current2){
                return current;
            }
            else
               current2 = current2->next;
        }
        current = current->next;
        current2 = headB;
    }
    return NULL;
}