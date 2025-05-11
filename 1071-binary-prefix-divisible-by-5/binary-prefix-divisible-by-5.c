/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* arr = (bool*)malloc(numsSize * sizeof(bool));
    int index = 0;
    int count = 0;
    for(int i=0 ; i<numsSize ; i++){
        count = (count*2+nums[i])%5;
        if(count%5==0){
            arr[index++] = true;
        }
        else{
            arr[index++] = false;
        }
    }
    *returnSize = index;
    return arr;
}