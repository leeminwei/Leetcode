int cmp(const void* a,const void*b){
    return *(int*)a-*(int*)b;
}
int compare(int* a,int asize,int k){
    qsort(a,asize,sizeof(int),cmp);
    for(int i=0 ; i<asize ; i++){
        for(int j=i+1 ; j<asize ; j++){
            if(a[i]==a[j]){
                for(int k=j ; k<asize-1 ; k++){
                    a[k] = a[k+1];
                }
                j--;
                asize--;
            }
        }
    }
    int index = 0;
    int count = 0;
    for(int i=1 ; i<=k ; i++){
        if(a[index++] == i)
            count++;
        if(count==k)
            return 1;
    }
    return 0;
}
int minOperations(int* nums, int numsSize, int k) {
    int* arr = malloc(51*sizeof(int));
    int index = 0;
    int answer = 0;
    for(int i=numsSize-1 ; i>=0 ; i--){
        arr[index++] = nums[i];
        if(compare(arr,index,k)==1)
            return numsSize-i; 
    }
    return numsSize;
}