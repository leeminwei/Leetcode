int minStartValue(int* nums, int numsSize) {
    int min = 0;
    int count = 0;
    for(int i=0 ; i<numsSize ; i++){
        count+=nums[i];
        if(count<min){
            min = count;
        }
    }
    return abs(min)+1;
}