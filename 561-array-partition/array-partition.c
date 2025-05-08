int cmp(const void*a , const void*b){
    return *(int*)a - *(int*)b;
}
int findmin(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}
int arrayPairSum(int* nums, int numsSize) {
    int sum = 0;
    int index = 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    while(index<=numsSize-2){
        sum += findmin(nums[index],nums[index+1]);
        index = index+2;
    }
    return sum;
}