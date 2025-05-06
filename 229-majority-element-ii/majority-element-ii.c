/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int key;
    int freq;
    UT_hash_handle hh;
}hash;
int* majorityElement(int* nums, int numsSize, int* returnSize) {
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
    int* arr = malloc(numsSize*sizeof(int));
    int number = 0;
    int max = numsSize/3;
    for(entry = map ; entry!=NULL ; entry = entry->hh.next){
        if(entry->freq > max){
            printf("major element = %d\n",entry->key);
            arr[number] = entry->key;
            number++;
        }
    }
    *returnSize = number;
    return arr;
}