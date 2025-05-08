int cmp(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}
int maximumProduct(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int sum = nums[0]*nums[1]*nums[numsSize-1];
    int sum2 = nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    if(sum>sum2)
        return sum;
    else
        return sum2;
}