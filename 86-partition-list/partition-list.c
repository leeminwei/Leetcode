/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* current = head;
    //建立小於x的串列
    struct ListNode* small = (struct ListNode*)malloc(sizeof(struct ListNode));
    small->next = NULL;
    struct ListNode* small_dummy = small;
    
    //建立大於等於x的串列
    struct ListNode* big = (struct ListNode*)malloc(sizeof(struct ListNode));
    big->next = NULL;
    struct ListNode* big_dummy = big;

    while(current!=NULL){
        //當前的val小於x
        if(current->val<x){
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = current->val;
            new->next = NULL;
            small->next = new;
            small = small->next;
        }
        //當前的val大於等於x
        else{
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = current->val;
            new->next = NULL;
            big->next = new;
            big = big->next;
        }
        current = current->next;
    }

    //因為數值較大的串列會在尾部所以要讓他接到NULL
    big->next = NULL;

    //最後將small串列和big串列接在一起
    small->next = big_dummy->next;
    
    return small_dummy->next;
}