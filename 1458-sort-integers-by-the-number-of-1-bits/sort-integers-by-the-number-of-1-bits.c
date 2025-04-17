/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bitcount(int n) {
    int count = 0;
    while(n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    for(int i=0 ; i<arrSize ; i++){
        for(int j=i+1 ; j<arrSize ; j++){
            if(arr[i]>arr[j]){
                int first = arr[i];
                arr[i] = arr[j];
                arr[j] = first;
            }
        }  
    }
    for(int i=0 ; i<arrSize ; i++){
        for(int j=i+1 ; j<arrSize ; j++){
            if(bitcount(arr[i])>bitcount(arr[j])||(bitcount(arr[i]) == bitcount(arr[j]) && arr[i] > arr[j])){
                int first = arr[i];
                arr[i] = arr[j];
                arr[j] = first;
            }
        }
    }
    *returnSize = arrSize;
    return arr;
}
/*
    for(int i=0 ;i<arrSize ; i++){
        printf("%d\n",arr[i]);
    }
    */