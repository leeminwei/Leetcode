/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    typedef struct ListNode ListNode;
    ListNode* cur = head;
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = NULL;
    ListNode* tail = dummy;
    int count = 0;
    while (cur != NULL) {
        //如果這時dummy是空的，就直接把head的第一個節點接到dummy後面
        if (tail == dummy) {
            ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
            newnode->val = cur->val;
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
            count = 1;
        }
        //如果dummy不是空的，就要確認大小
        else{
            ListNode* prev = dummy;
            ListNode* find = dummy->next;
            count = 0;
            while (find != NULL) {
                if (cur->val < find->val) {
                    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
                    newnode->val = cur->val;
                    newnode->next = NULL;
                    prev->next = newnode;
                    newnode->next = find;
                    count = 1;
                    break;
                }
                prev = prev->next;
                find = find->next;
            }
            if (count == 0) {
                ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
                newnode->val = cur->val;
                newnode->next = NULL;
                prev->next = newnode;
            }
        }
        cur = cur->next;
    }
    return dummy->next;
}