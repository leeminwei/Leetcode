/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* odd = (struct ListNode*)malloc(sizeof(struct ListNode));
    odd->next = NULL;
    struct ListNode* odd_dummy = odd;
    struct ListNode* even = (struct ListNode*)malloc(sizeof(struct ListNode));
    even->next = NULL;
    struct ListNode* even_dummy = even;
    struct ListNode* current = head;
    int count = 1;
    while(current!=NULL){
        if(count%2==0){
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = current->val;
            new->next = NULL;
            even->next = new;
            even = even->next;
        }
        else{
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = current->val;
            new->next = NULL;
            odd->next = new;
            odd = odd->next;
        }
        current = current->next;
        count++;
    }
    even->next = NULL;
    odd->next = even_dummy->next;
    return odd_dummy->next;
}