/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* copylist(struct ListNode* head, int* len) {
    typedef struct ListNode listnode;
    listnode* cur = head;
    listnode* newhead = (listnode*)malloc(sizeof(listnode));
    newhead->next = NULL;
    listnode* tail = newhead;
    while (cur != NULL) {
        (*len)++;
        listnode* newnode = (listnode*)malloc(sizeof(listnode));
        newnode->val = cur->val;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        cur = cur->next;
    }
    return newhead->next;
}
struct ListNode* swapNodes(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    typedef struct ListNode listnode;
    int len = 0;
    listnode* newhead = copylist(head, &len);
    listnode* prev = NULL;
    listnode* cur = head;
    while (cur != NULL) {
        listnode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    listnode* original = newhead;
    listnode* reverse = prev;
    int idx = len-k+1;
    int left;
    int right;
    if (idx > k) {
        left = k;
        right = idx;
    } 
    else{
        left = idx;
        right = k;
    }
    for (int i=1 ; i<right ; i++) {
        if (i == left) {
            original->val = reverse->val;
        }
        original = original->next;
        reverse = reverse->next;
    }
    original->val = reverse->val;
    return newhead;
}