int subsetXORSum(int* nums, int numsSize) {
    int total = 1<<numsSize;
    int answer = 0;
    for(int i=0 ; i<total ; i++){
        int count = 0;
        for(int j=0 ; j<numsSize ; j++){
            if(i&(1<<j)){
                count ^= nums[j];
            }
        }
        answer += count;
    }
    return answer;
}