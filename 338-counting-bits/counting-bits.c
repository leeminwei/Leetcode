/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countone(int a){
    int count = 0;
    while(a){
        a &= (a-1);
        count++;
    }
    return count;
}
int* countBits(int n, int* returnSize) {
    int *arr = malloc((n+1)*sizeof(int));
    for(int i=0 ; i<=n ; i++){
        arr[i] = countone(i);
    }
    *returnSize = n+1;
    return arr;
}