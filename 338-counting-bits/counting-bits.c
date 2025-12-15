/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countone(int n){
    int count = 0;
    while (n!=0) {
        n &= (n-1);
        count++;
    }
    return count;
}

int* countBits(int n, int* returnSize) {
    (*returnSize) = n+1;
    int* arr = (int*)malloc((*returnSize) * sizeof(int));
    int idx = 0;
    for (int i=0 ; i<=n ; i++) {
        arr[idx++] = countone(i);
    }
    return arr;
}