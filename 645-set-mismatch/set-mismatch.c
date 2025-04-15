/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    int check = 0;
    int number = 0;
    int a=1;
    int *arr = (int*)malloc(numsSize*sizeof(int));
    for(int i=0 ; i<numsSize ; i++){
        arr[i] = a;
        a++;
    }
    for(int i=0 ; i<numsSize ; i++){
        int found = 0;
        for(int j=0 ; j<numsSize ; j++){
            if(arr[i]==nums[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            number = arr[i];
            break;
        }
    }
    for(int i=0 ; i<numsSize ; i++){
        for(int j=i+1 ; j<numsSize ; j++){
            if(nums[i]==nums[j]){
                count = nums[i];
                break;
            }
        }
    }
    int *answer = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    answer[0] = count;
    answer[1] = number;
    return answer;
}