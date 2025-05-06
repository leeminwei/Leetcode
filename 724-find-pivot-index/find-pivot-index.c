int sum(int* nums,int start, int end){
    int count = 0;
    for(int i=start ; i<=end ; i++){
        count+=nums[i];
    }
    return count;
}
int pivotIndex(int* nums, int numsSize) {
    for(int i=0 ; i<numsSize ; i++){
        int left = sum(nums,0,i-1);
        int right = sum(nums,i+1,numsSize-1);
        if(left==right)
            return i;
    }
    return -1;
}