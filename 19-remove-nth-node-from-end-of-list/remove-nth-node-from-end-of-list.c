/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* cur = head;
    int size = 0;
    while (cur != NULL) {
        size++;
        cur = cur->next;
    }
    if (size == 1 && n == 1) {
        return NULL;
    }
    struct ListNode* cur1 = head;
    int count = 0;
    struct ListNode* newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
    newlist->next = NULL;
    struct ListNode* tail = newlist;
    while (cur1 != NULL) {
        if (count == size-n) {
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
        count++;
    }
    return newlist->next;
}