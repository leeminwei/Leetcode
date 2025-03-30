/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i=digitsSize-1 ; i>=0 ; i--){
        if(digits[i]<9){
            digits[i]++;
            *returnSize = digitsSize;
            int* arr = (int*)malloc(digitsSize * sizeof(int));
            for(int i=0 ; i<digitsSize ; i++){
                arr[i] = digits[i];
            }
            return arr;
        }
        else
            digits[i]=0;
    }
    *returnSize = digitsSize + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    result[0] = 1;
    for (int i = 1; i < *returnSize; i++) {
        result[i] = 0;
    }
    return result;
}