/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct{
    int key;
    int freq;
    UT_hash_handle hh;
}hash;
int cmp(const void* a, const void* b){
    hash* ha = *(hash**)a;
    hash* hb = *(hash**)b;
    return ha->key - hb->key;
}
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* current = head;
    hash* map = NULL;
    hash* entry = NULL;
    while(current!=NULL){
        int key = current->val;
        printf("key = %d",key);
        //HASH_FIND_INT(map,&key,entry);       
        entry = malloc(sizeof(hash));
        entry->key = key;
        entry->freq = 1;
        HASH_ADD_INT(map,key,entry);
        current = current->next;
    }
    //hashmap依照key的大小進行排序
    int count = HASH_COUNT(map);
    hash** arr = malloc(count*sizeof(hash*));
    int index = 0;
    for(entry = map ; entry!=NULL ; entry = entry->hh.next){
        arr[index++] = entry;
    }
    qsort(arr,index,sizeof(hash*),cmp);
    //有了排序完的hashmap
    //依照hashmap的排序 創建新的鏈結串列(dummy)
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    struct ListNode* dummy = tail;
    for(int i=0 ; i<index ; i++){
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = arr[i]->key;
        new->next = NULL;
        tail->next = new;
        tail = tail->next;
    }
    tail->next = NULL;
    return dummy->next;
}