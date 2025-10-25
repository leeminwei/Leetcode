/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* cur = dummy;
    int num = 0;
    int carry = 0;
    int x;
    int y;
    while (cur1 != NULL || cur2 != NULL) {
        if (cur1 == NULL) {
            x = 0;
        }
        else{
            x = cur1->val;
        }
        if (cur2 == NULL) {
            y = 0;
        }
        else{
            y = cur2->val;
        }
        num = x + y + carry;
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = num%10;
        newnode->next = NULL;
        cur->next = newnode;
        cur = newnode;
        carry = num/10;
        if (cur1 != NULL) cur1 = cur1->next;
        if (cur2 != NULL) cur2 = cur2->next;
    }
    if (carry != 0) {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = carry;
        newnode->next = NULL;
        cur->next = newnode;
    }
    return dummy->next;
}