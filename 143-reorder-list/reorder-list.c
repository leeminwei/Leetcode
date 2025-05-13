/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    //if(head==NULL || head->next==NULL) return head;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    //找到中間的節點(slow)
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    //反轉後半部不包括中點
    struct ListNode* prev = NULL;
    struct ListNode* current = slow->next;
    while(current!=NULL){
        struct ListNode* step = current->next;
        current->next = prev;
        prev = current;
        current = step;
    }
    slow->next = NULL; //將前半部和後半部斷開
    struct ListNode* reverse = prev;
    struct ListNode* original = head;
    //printf("%d\n",original->next->next->val);
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    struct ListNode* dummy = tail;
    while(reverse!=NULL&&original!=NULL){
        tail->next = original;
        tail = tail->next;
        original = original->next;
        tail->next = reverse;
        tail = tail->next;
        reverse = reverse->next;
    }
    if(reverse==NULL){
        tail->next = original;
    }
    else
        tail->next = reverse;
    head = dummy->next;
}