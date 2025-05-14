/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k==0||head==NULL||head->next==NULL) return head;
    struct ListNode* copy = head;
    struct ListNode* copy2 = head;
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    struct ListNode* dummy = tail;
    int count = 0;
    //複製一段新的串列dummy->next = 12345
    while(copy!=NULL){
        //new就是複製出來的一個獨立新節點
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = copy->val;
        new->next = NULL;
        tail->next = new;
        tail = tail->next;
        copy = copy->next;
        count++;
    }
    //將兩個串列接上變成1234512345
    struct ListNode* newdummy = head; 
    while(newdummy->next!=NULL){
        newdummy = newdummy->next;
    }
    newdummy->next = dummy->next;
    int start = count-(k%count);
    struct ListNode* current = head;
    struct ListNode* answer = (struct ListNode*)malloc(sizeof(struct ListNode));
    answer->next = NULL;
    struct ListNode* result = answer;
    int check = 0;
    while(current!=NULL){
        if(check >= start){
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = current->val;
            new->next = NULL;
            answer->next = new;
            answer = answer->next;
        }
        if(check==(count+start-1)){
            break;
        }
        current = current->next;
        check++;
    }
    return result->next;
}