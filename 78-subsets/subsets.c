/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1<<numsSize; //總共多少個子集合(2的numsSize次方)
    int** arr = (int**)malloc(total * sizeof(int*));
    *returnSize = total;
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    for (int i=0 ; i<total ; i++) {
        int* subset = (int*)malloc(numsSize * sizeof(int));
        int index = 0;
        for (int j=0 ; j<numsSize ; j++) {
            if ((i & (1<<j)) != 0) {
                subset[index++] = nums[j];
            }
        }
        arr[i] = subset;
        (*returnColumnSizes)[i] = index;
    }
    return arr;
}