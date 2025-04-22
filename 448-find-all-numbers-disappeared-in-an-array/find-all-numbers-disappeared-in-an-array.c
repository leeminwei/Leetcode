/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *freq = calloc(numsSize + 1, sizeof(int));   
    int *arr = (int*)malloc(sizeof(int) * numsSize);
    for(int i=0 ; i<numsSize ; i++){
        freq[nums[i]]++;
    }
    int size = 0;
    for(int i = 1; i <= numsSize; i++) {
        if(freq[i] == 0){
            arr[size++] = i;
        }
    }
    arr = realloc(arr, sizeof(int) * size);
    *returnSize = size;
    return arr;
}