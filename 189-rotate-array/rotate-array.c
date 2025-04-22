void rotate(int* nums, int numsSize, int k) {
    int *arr = malloc((numsSize+numsSize)*sizeof(int));
    for(int i=0 ; i<numsSize ; i++){
        arr[i] = nums[i];
    }
    for(int i=0 ; i<numsSize ; i++){
        arr[i+numsSize] = nums[i];
    }
    for(int i=0 ; i<numsSize+numsSize ; i++){
        printf("%d",arr[i]);
    }
    int count = k%numsSize;
    printf("\n%d",count);
    int *answer = malloc((numsSize+1)*sizeof(int));
    int number = 0;
    for(int i=numsSize-count ; i<numsSize-count+numsSize ; i++){
        answer[number] = arr[i];
        number++;
    }
    for(int i=0 ; i<numsSize ; i++){
        nums[i] = answer[i];
    }
}