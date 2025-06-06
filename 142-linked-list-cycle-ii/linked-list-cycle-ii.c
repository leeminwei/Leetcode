/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;   
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            struct ListNode* finder = head;
            while(finder != slow){
                finder = finder->next;
                slow = slow->next;
            }
            return finder;
        }
    }
    return 0;
}