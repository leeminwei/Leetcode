/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *current = headA;
    struct ListNode *current2 = headB;
    while(current!=NULL || current2!=NULL){
        if(current==NULL)
            current = headA;
        if(current2==NULL)
            current2 = headB;
        if(current==current2)
            return current;
        current = current->next;
        current2 = current2->next;
    }
    return 0;
}
/*
 while(current!=NULL){
        while(current2!=NULL){
            if(current == current2){
                return current;
            }
            else
               current2 = current2->next;
               printf("current2 = %d",current2);
        }
        current = current->next;
        printf("current = %d",current);
        current2 = headB;  //要在讓headB從頭驗證一次
    }
    return NULL;
    */