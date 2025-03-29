void moveZeroes(int* nums, int numsSize) {
    int number = 0;
    for(int i=0 ; i<numsSize ; i++){
        if (nums[i] != 0) {
            nums[number] = nums[i];
            number++;
        }
    }
    for (int j = number; j < numsSize; j++) {
        nums[j] = 0;
    }
}