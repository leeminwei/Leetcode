/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* arr = malloc(numsSize*sizeof(int));
    int number = 0;
    int count = 0;
    for(int i=0 ; i<numsSize ; i++){
        count+=nums[i];
        arr[number] = count;
        number++;
    }
    *returnSize = number;
    return arr;
}