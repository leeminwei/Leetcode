typedef struct{
    int key;
    int freq;
    int position;
    UT_hash_handle hh;
}hash;
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    hash* map = NULL;
    hash* entry = NULL;
    int diff = 0;
    for(int i=0 ; i<numsSize ; i++){
        int key = nums[i];
        HASH_FIND_INT(map, &key, entry);
        if(entry==NULL){
            entry = malloc(sizeof(hash));
            entry->key = nums[i];
            entry->freq = 1;
            entry->position = i;
            HASH_ADD_INT(map, key, entry);
        }
        else{
            int first = entry->position;
            printf("%d first position is %d\n",key,first);
            diff = i-first;
            if(diff<=k){
                return true;
            }
            entry->position = i;
        }
    }
    return false;
}