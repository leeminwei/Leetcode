/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*  Time Limit
int count(int* nums,int start,int end){
    int answer = 1;
    //if(end<start) return 0;
    for(int i=start ; i<=end ; i++){
        answer *= nums[i];
    }
    return answer;
}
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* arr = malloc(numsSize*sizeof(int));
    int number = 0;
    for(int i=0 ; i<numsSize ; i++){
        int left = count(nums,0,i-1);
        int right = count(nums,i+1,numsSize-1);
        arr[number] = left*right;
        number++;
    }
    *returnSize = number;
    return arr;
}
*/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* prefix = malloc(numsSize*sizeof(int));
    int* postfix = malloc(numsSize*sizeof(int));
    int* answer = malloc(numsSize*sizeof(int));
    prefix[0] = 1;
    for(int i = 1; i < numsSize; i++){
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    postfix[numsSize - 1] = 1;
    for(int i = numsSize - 2; i >= 0; i--){
        postfix[i] = postfix[i + 1] * nums[i + 1];
    }

    for(int i = 0; i < numsSize; i++){
        answer[i] = prefix[i] * postfix[i];
    }

    free(prefix);
    free(postfix);
    *returnSize = numsSize;
    return answer;
}