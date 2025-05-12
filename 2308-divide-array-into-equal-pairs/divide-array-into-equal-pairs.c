typedef struct{
    int key;
    int freq;
    UT_hash_handle hh;
}hash;
bool divideArray(int* nums, int numsSize) {
    if(numsSize%2!=0) return false;
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
    for(entry=map ; entry!=NULL ; entry = entry->hh.next){
        if(entry->freq%2!=0)
            return false;
    }
    return true;
}