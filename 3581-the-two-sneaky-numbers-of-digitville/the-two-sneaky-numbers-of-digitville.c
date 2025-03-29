/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    int size = 1;
    int *arr = NULL;
    *returnSize = 0;
    for(int i = 0 ; i<numsSize ; i++){
        for(int j = i+1 ; j < numsSize ; j++){
            if(nums[i] == nums[j]){
                arr = (int*)realloc(arr, (*returnSize + 1) * sizeof(int));
                arr[*returnSize] = nums[j];
                (*returnSize)++;
            }
            else
                continue;         
        }
    }
   return arr;
}