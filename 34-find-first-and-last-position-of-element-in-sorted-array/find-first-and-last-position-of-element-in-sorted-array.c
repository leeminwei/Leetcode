/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* arr = calloc(2,sizeof(int));
    int check = 0;
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]==target){
            arr[0] = i;
            check = 1;
            break;
        }
    }
    for(int i=numsSize-1 ; i>=0 ; i--){
        if(nums[i]==target){
            arr[1] = i;
            check = 1;
            break;
        }
    }
    if(check==0 && arr[1]==0){
        arr[0] = -1;
        arr[1] = -1;
    }
    *returnSize = 2;
    return arr;
}