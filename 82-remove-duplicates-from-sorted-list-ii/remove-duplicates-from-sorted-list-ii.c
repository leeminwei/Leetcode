/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur1 = head;
    struct ListNode* cur2 = head;
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = NULL;
    struct ListNode* tail = newhead;
    int count = 0;
    while (cur1 != NULL) {
        count = 0;
        while (cur2 != NULL) {
            if (cur2->val == cur1->val && cur2 != cur1) {
                count = 1;
                printf("check\n");
            }
            cur2 = cur2->next;
        }
        if (count == 0) {
            struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val = cur1->val;
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
        }
        cur1 = cur1->next;
        cur2 = head;
    }
    return newhead->next;
}