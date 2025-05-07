int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int right = 0;
    int minlen = numsSize+1;
    int size = 0;
    int count = 0;
    while(right < numsSize){
        count += nums[right];
        while(count>=target){
            int size = right-left+1;
            if(size<minlen)
                minlen = size;
            count = count-nums[left];
            left++;
        }
        right++;
    }
    if(minlen==numsSize+1) return 0;
    else return minlen;
}