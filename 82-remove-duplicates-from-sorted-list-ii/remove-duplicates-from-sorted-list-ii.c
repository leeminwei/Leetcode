/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL||head->next==NULL) return head;
    struct ListNode* current = head;
    struct ListNode* current2 = head;
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    struct ListNode* dummy = tail;
    int count = 0;
    while(current!=NULL){
        while(current2!=NULL){
            //printf("current = %d\n",current->val);
            //printf("current2 = %d\n",current2->val);
            if(current2==NULL)
                break;
            if(current->val == current2->val){
                count++;
            }
            current2 = current2->next;
        }
        if(count==1){
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = current->val;
            new->next = NULL;
            tail->next = new;
            tail = tail->next;
        }
        count = 0;
        current = current->next;
        current2 = head;
    }
    tail->next = NULL;
    return dummy->next;
}