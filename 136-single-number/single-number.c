int singleNumber(int* nums, int numsSize) {
    int number = numsSize;
    int *size = &number;
    int freq[60001]={0};
    for(int i=0 ; i<numsSize ; i++){
        freq[nums[i]+30000]++;
    }
    for(int i=0 ; i<*size ; i++){
        for(int j=i+1 ; j<*size ; j++){
            if(nums[i]==nums[j]){
                for(int k=j ; k<*size-1 ; k++){
                    nums[k] = nums[k+1];
                }
                (*size)--;
                j--;
            }
        }
    }
    for(int i=0 ; i<*size ;i++){
        printf("%d\n",freq[nums[i]+30000]);
        if(freq[nums[i]+30000] == 1)
            return nums[i];
    }
    return 0;
}