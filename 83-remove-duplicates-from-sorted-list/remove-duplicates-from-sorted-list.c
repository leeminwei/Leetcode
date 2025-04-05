/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* tail = dummy;
    struct ListNode* current = head;
    while(current!=NULL){
        if(current->next!=NULL && current->val == current->next->val){
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = current->val;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            while (current->next != NULL && current->val == current->next->val) {
                current = current->next;
            }
            current = current->next;
        }
        else{
            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = current->val;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            current = current->next;
        } 
    }
    return dummy->next;
}
    /*
    struct ListNode* current = head;
    while(current!=NULL){
        if(current->next != NULL && current->val == current->next->val){
            current->next = current->next->next;
        }
        else{
            printf("%d",current->val);
            current = current->next;
        }
    }
    return head;
}
*/