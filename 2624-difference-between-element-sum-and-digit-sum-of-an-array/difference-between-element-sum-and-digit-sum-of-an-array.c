int differenceOfSum(int* nums, int numsSize) {
    int sum = 0;
    int number = 0;
    for(int i=0 ; i<numsSize ; i++){
        sum = sum + nums[i];
    }
    for(int j=0 ; j<numsSize ; j++){
        if(nums[j]<10)
            number += nums[j];
        while(nums[j]>=10){
            number += nums[j] % 10;
            nums[j]/=10;
            printf("%d\n",nums[j]);
            if(nums[j]<10)
                number += nums[j];
        }
                
    }
    printf("sum = %d\n",sum);
    printf("number = %d\n",number);
    if(sum>number)
        return sum-number;
    else if (sum==number)
        return 0;
    else
        return number-sum;       
}