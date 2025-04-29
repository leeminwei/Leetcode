/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    int *arr = malloc(32*sizeof(int));
    int number = 0;
    while(n>=1){
        arr[number] = n%2;
        number++;
        n/=2;
    }
    int odd = 0;
    int even = 0;
    for(int i=0 ; i<number ; i++){
        if(i%2!=0 && arr[i]==1){
            odd++;
        }
        else if(i%2==0 && arr[i]==1){
            even++;
        }
    }
    *returnSize=2;
    arr = realloc(arr,(*returnSize)*sizeof(int));
    arr[0] = even;
    arr[1] = odd;
    return arr;
}
/*
for(int i=0 ; i<number ; i++){
        printf("%d",arr[i]);
    }
*/