/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *array = (int*)malloc(2 * sizeof(int));
    for(int i=0 ; i<numsSize ; i++){
        //printf("i = %d\n",i);
        for(int j=i+1 ; j<numsSize ; j++){
            //printf("j = %d\n",j);
            if(nums[i]+nums[j] == target){
                array[0] = i;
                array[1] = j;
                *returnSize = 2;
            }
            else
                continue;
        }
    }
    return array;
    /*
    for(int i=0 ; i<2 ; i++){
        printf("%d",array[i]);
    }
    */
}