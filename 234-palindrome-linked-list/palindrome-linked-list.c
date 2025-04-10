/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* previous = NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* step = NULL;
    while(slow!=NULL){
        step = slow->next;
        slow->next = previous;
        previous = slow;
        slow = step;
    }
    //slow->next = previous;
    struct ListNode* left = head;
    struct ListNode* right = previous;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}