int findDuplicate(int* nums, int numsSize) {
    int *freq = calloc(numsSize,sizeof(int));
    for(int i=0 ; i<numsSize  ; i++){
        freq[nums[i]]++;
        if(freq[nums[i]]>1){
            return nums[i];
        }
    }
    return 0;
}