int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 1;

    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == candidate) {
            count++;
        } else {
            count--;
            if(count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;
}
/*
int answer = 0;
    for(int i=0 ; i<numsSize ; i++){
        int count = 0;
        for(int j=i ; j<numsSize ; j++){
            if(nums[i] == nums[j]){
                count = count+1;
            }
        }
        if(count>(numsSize/2)){
            answer = nums[i];
            break;
        }
    }
    return answer;
*/