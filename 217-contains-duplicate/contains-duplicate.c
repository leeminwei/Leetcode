bool containsDuplicate(int* nums, int numsSize) {
    int min = nums[0];
    int max = nums[0];
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]<min)
            min = nums[i];
        else if(nums[i]>max)
            max = nums[i];
    }
    int *freq = calloc((max-min+1),sizeof(int));
    for(int i=0 ; i<numsSize ; i++){
        freq[nums[i]-min]++;
        if(freq[nums[i]-min]>1)
            return true;
    }
    return false;
}
    //for(int)
    /*
    for(int i=0 ; i<numsSize ; i++){
        for(int j=i+1 ; j<numsSize ; j++){
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
    */
