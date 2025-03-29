int searchInsert(int* nums, int numsSize, int target) {
    int count = 0;
    for(int i = 0 ; i<numsSize ; i++){
        if (target > nums[i])
            count++;
        else if (nums[i] == target)
            break;
    }
    return count;
}