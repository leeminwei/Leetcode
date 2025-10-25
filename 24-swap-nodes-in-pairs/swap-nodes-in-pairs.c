/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* createNode(int num) {
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = num;
    newnode->next = NULL;
    return newnode;
}
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head; 
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* tail = dummy;
    struct ListNode* cur1 = head;
    struct ListNode* cur2 = head;
    while (cur2->next != NULL && cur2->next->next != NULL) {
        struct ListNode* newnode;
        newnode = createNode(cur2->next->val);
        tail->next = newnode;
        tail = tail->next;
        newnode = createNode(cur1->val);
        tail->next = newnode;
        tail = tail->next;
        cur2 = cur2->next->next;
        cur1 = cur1->next->next;
    }
    if (cur2->next != NULL) {
        tail->next = createNode(cur2->next->val);
        tail = tail->next;
    }
    if (cur1 != NULL) {
        tail->next = createNode(cur1->val);
        tail = tail->next;
    }
    return dummy->next;
}
/*
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* current2 = head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* result = dummy;
    if(current==NULL) return NULL;
    if(current->next==NULL) return current;
    //printf("%d",current->next->val);
    //printf("%d",current->val);
    //current記錄偶數位 current2記錄奇數位
    //while迴圈的判斷要確保有成對的節點可以處理
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
*/  