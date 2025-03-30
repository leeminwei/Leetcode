int missingNumber(int* nums, int numsSize) {
    int number = numsSize+1;
    int count = 0;
    int clock = 0;
    int* arr = (int*)malloc((numsSize + 1) * sizeof(int));
    for(int i=0; i<numsSize+1 ; i++){
        arr[i] = i;
    }
    for(int i=0 ; i<number ; i++){
        for(int j=0 ; j<numsSize ; j++){
            if(arr[i] != nums[j]){
                clock++;
            }
            if(clock == numsSize)
                return arr[i];           
        }
        clock = 0;
    }
    return 0;
}