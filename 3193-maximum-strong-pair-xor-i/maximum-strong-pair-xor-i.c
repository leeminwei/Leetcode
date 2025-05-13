int min(int a,int b){
    if(a<b) return a;
    else return b;
}
int maximumStrongPairXor(int* nums, int numsSize) {
    int max = 0;
    int xor = 0;
    for(int i=0 ; i<numsSize ; i++){
        for(int j=i ; j<numsSize ; j++){
            if(abs(nums[i]-nums[j])<=min(nums[i],nums[j])){
                xor = nums[i]^nums[j];
                if(xor>max)
                    max = xor;
            }
        }
    }
    return max;
}