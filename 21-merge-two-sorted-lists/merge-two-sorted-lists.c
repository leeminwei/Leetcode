/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    while (list1 && list2) {
        if(list1 -> val < list2 -> val){
            tail -> next = list1; 
            list1 = list1 -> next;
        }
        else{
            tail -> next = list2; 
            list2 = list2 -> next;
        }
        tail = tail->next;
    }
     // 把剩下的節點接上去（其中一個已經是 NULL）
    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    // 回傳合併後 linked list 的頭（跳過 dummy）
    return dummy.next;
}