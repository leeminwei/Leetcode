/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize-1;
    int *arr = malloc(2*sizeof(int));
    while(left<right){
        if(numbers[left]+numbers[right]>target)
            right--;
        else if(numbers[left]+numbers[right]<target)
            left++;
        if(numbers[left]+numbers[right]==target){
            arr[0] = left+1;
            arr[1] = right+1;
            *returnSize = 2;
            return arr;
        }
    }
    return 0;
}
/* Time Limit
int* arr = malloc(2*sizeof(int));
    for(int i=0 ; i<numbersSize ; i++){
        for(int j=i+1 ; j<numbersSize ; j++){
            if(numbers[i]+numbers[j]==target){
                arr[0] = i+1;
                arr[1] = j+1;
                *returnSize = 2;
                return arr;
            }
        }
    }
    return 0;
*/