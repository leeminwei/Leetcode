/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* current2 = head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* result = dummy;
    if(current==NULL) return NULL;
    if(current->next==NULL) return current;
    //printf("%d",current->val);
    while(current2!=NULL&&current2->next!=NULL){
        current = current2->next;             // 偶數位（第2個）
        struct ListNode* next = current->next; // 下一組起始
        dummy->next = current;                // 接第2個
        dummy = dummy->next;
        dummy->next = current2;               // 接第1個
        dummy = dummy->next;
        current2 = next;                      // 移到下一組
    }
    dummy->next = current2;
    return result->next;
}