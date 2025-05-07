/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int check(int* arr,int size,int k){
    for(int i=0 ; i<size ; i++){
        if(arr[i]==k)
            return 0;
    }
    return 1;
}
typedef struct{
    int key;
    int freq;
    UT_hash_handle hh;
}hash;
int cmp(const void* a, const void* b) {
    hash* ha = *(hash**)a;
    hash* hb = *(hash**)b;
    return hb->freq - ha->freq;  // 由大到小排序
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    hash* map = NULL;
    hash* entry = NULL;
    for(int i=0 ; i<numsSize ; i++){
        int key = nums[i];
        HASH_FIND_INT(map,&key,entry);
        if(entry==NULL){
            entry = malloc(sizeof(hash));
            entry->key = key;
            entry->freq = 1;
            HASH_ADD_INT(map,key,entry);
        }
        else{
            entry->freq++;
        }
    }
    // 將所有 entry 放入陣列
    int count = HASH_COUNT(map);
    hash** arr = malloc(count * sizeof(hash*));
    int idx = 0;
    for (entry = map; entry != NULL; entry = entry->hh.next) {
        arr[idx++] = entry;
    }
    // 排序
    qsort(arr, count, sizeof(hash*), cmp);
    int* answer = malloc(idx*sizeof(int));
    int number = 0;
    for(int i=0 ; i<idx ; i++){
        if(check(answer,number,arr[i]->key)!=0){
            answer[number++] = arr[i]->key;
        }
        if(number==k){
            *returnSize = k;
            return answer;
        }
    }
    return 0;
}