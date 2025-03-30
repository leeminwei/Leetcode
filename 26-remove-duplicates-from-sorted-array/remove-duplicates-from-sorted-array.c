int removeDuplicates(int* nums, int numsSize) {
    int number = numsSize;
    int *size = &number;
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return 1;
    printf("size = %d\n",*size);
    for(int i=0 ; i<*size-1 ; i++){
        if(nums[i]==nums[i+1]){
            for(int j=i+1 ; j<*size-1 ; j++){
                nums[j] = nums[j+1];
            }
            (*size)--;
            i--;
        }
        
    }
    for(int i=0 ; i<*size ; i++){
        printf("%d\n",nums[i]);
    }
    return *size;
}
/*
int *stack = (int*)malloc(numsSize*sizeof(int));
    int count = 0;
    stack[0] = nums[0];
    for(int i=0 ; i<numsSize ; i++){
        if(stack[count]!=nums[i]){
            count++;
            stack[count]=nums[i];
        }
    }
    for(int i=0 ; i<count+1 ; i++){
        printf("%d\n",stack[i]);
    }
    return stack;
*/