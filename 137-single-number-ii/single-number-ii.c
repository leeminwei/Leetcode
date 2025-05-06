typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} hash;
int singleNumber(int* nums, int numsSize) {
    hash *map = NULL;
    hash *entry = NULL;
    for(int i=0 ; i<numsSize ; i++){
        int key = nums[i];
        HASH_FIND_INT(map, &key, entry);
        if(entry==NULL){
            entry = malloc(sizeof(hash));
            entry->key = key;
            entry->value = 1;
            HASH_ADD_INT(map, key, entry);
        }
        else{
            entry->value++;
        }
    }
    for (entry = map; entry != NULL; entry = entry->hh.next) {
        printf("數字 %d 出現 %d 次\n", entry->key, entry->value);
        if(entry->value == 1)
            return entry->key;
    }
    return 0;
}

//memory problem
/*
int min = nums[0];
    int max = nums[0];
    
    // 找最小值和最大值
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] > max)
            max = nums[i];
    }  
    // 動態開一個夠大的 freq array
    int size = max - min + 1;
    int *freq = calloc(size, sizeof(int));
    for(int i=0 ; i<numsSize ; i++){
        freq[nums[i]-min]++;
    }
    int answer = 0;
    for(int i=0 ; i<numsSize ; i++){
        if(freq[nums[i]-min]==1){
            answer = nums[i];
            break;
        }
    }
    free(freq);
    return answer;
*/
