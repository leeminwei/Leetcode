int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int currentsum = 0;
    for(int i=0 ; i<numsSize ; i++){
        if(currentsum<0)
            currentsum = 0;
        currentsum += nums[i];
        if(currentsum>max)
            max = currentsum;
    }
    return max;
}