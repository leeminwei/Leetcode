/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || (head->next == NULL && n==1)) return NULL;
    struct ListNode* cur = head;
    int count = 0;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    struct ListNode* cur1 = head;
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = NULL;
    struct ListNode* tail = newhead;
    int idx = 0;
    while (cur1 != NULL) {
        if (idx == count-n) {
            cur1 = cur1->next;
        }
        else{
            struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val = cur1->val;
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
            cur1 = cur1->next;
        }
        idx++;
    }
    return newhead->next;
}