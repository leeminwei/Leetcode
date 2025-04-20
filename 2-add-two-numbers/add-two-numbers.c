/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    newhead->next = NULL;
    struct ListNode* tail = newhead;
    struct ListNode* current = l1;
    struct ListNode* current2 = l2;
    int count = 0;
    int carry = 0;
    while(current != NULL || current2 != NULL || carry){
        struct ListNode* arr = malloc(sizeof(struct ListNode));
        arr->next = NULL;
        int val,val2;
        if(current != NULL && current2 == NULL){
            val = current->val;
            val2 = 0;
        }
        else if(current2 != NULL && current == NULL){
            val2 = current2->val;
            val = 0;
        }
        else if(current != NULL && current2 != NULL){
            val = current->val;
            val2 = current2->val;
        }
        else{
            val = 0;
            val2 = 0;
        }
        count = val + val2 + carry;
        if(count>=10){
            arr->val = count-10;
            carry = 1;
        }
        else {
            arr->val = count;
            carry = 0;
        }
        if (current) current = current->next;
        if (current2) current2 = current2->next;
        tail->next = arr;
        tail = arr;
    }
    return newhead->next;
}