/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next = NULL;
    struct ListNode* tail1 = list1;
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next = NULL;
    struct ListNode* tail2 = list2;
    struct ListNode* cur = head;
    while (cur != NULL) {
        if (cur->val >= x) {
            struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val = cur->val;
            newnode->next = NULL;
            tail1->next = newnode;
            tail1 = newnode;
        }
        else{
            struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val = cur->val;
            newnode->next = NULL;
            tail2->next = newnode;
            tail2 = newnode;
        }
        cur = cur->next;
    }
    tail2->next = list1->next;
    return list2->next;
}