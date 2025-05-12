int countone(int n){
    int count = 0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}
int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    int one = 0;
    int answer = 0;
    for(int i=0 ; i<numsSize ; i++){
        one = countone(i);
        if(one==k){
            answer+=nums[i];
        }
    }
    return answer;
}