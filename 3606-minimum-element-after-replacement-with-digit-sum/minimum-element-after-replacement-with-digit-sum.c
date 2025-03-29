int minElement(int* nums, int numsSize) {
    int answer = 0;
    int Single_digit;
    int rest_digit;
    int rest_single_digit;
    int digit;
    int digit_single_digit;
    int rest;
    int min = 0;
    int *p = (int *)malloc(sizeof(int)*(numsSize+1));
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i] == 10000)
            return min = 1;
        printf("現在測試%d = %d\n",i,nums[i]);
        if(nums[i]<100 && nums[i]>9){
            Single_digit = nums[i] % 10;
            rest_digit = nums[i] / 10;
            answer = Single_digit + rest_digit;
            p[i] = answer;
            if(numsSize == 1)
                min = p[i];
            if(i == 0)
                min = p[i];
            else if(p[i] < min)
                min = p[i];
            else 
                min = min;
            
        }
        else if(nums[i] > 99 && nums[i] < 1000){
            Single_digit = nums[i] % 10;
            rest_digit = nums[i] / 10;
            rest_single_digit = rest_digit % 10;
            digit = rest_digit / 10;
            answer = Single_digit + rest_single_digit + digit;
            p[i] = answer;
            if(numsSize == 1)
                min = p[i];
            if(i == 0)
                min = p[i];
            else if(p[i] < min)
                min = p[i];
            else 
                min = min;
            
        }
        else if(nums[i] > 999 && nums[i] < 10000){
            Single_digit = nums[i] % 10;
            rest_digit = nums[i] / 10;
            rest_single_digit = rest_digit % 10;
            digit = rest_digit / 10;
            digit_single_digit = digit % 10;
            rest = digit / 10;
            answer = Single_digit + rest_single_digit + digit_single_digit + rest;
            p[i] = answer;
            if(numsSize == 1)
                min = p[i];
            if(i == 0)
                min = p[i];
            else if(p[i] < min)
                min = p[i];
            else 
                min = min;
           
        }
        else{
            p[i] = nums[i];
            printf("%d\n",p[i]);
            printf("現在的min = %d\n",min);
            printf("現在的p[i] = %d\n",p[i]);
            if(numsSize == 1)
                min = p[i];
            if(i == 0)
                min = p[i];
            else if(p[i] < min)
                min = p[i];
            else 
                min = min;
            
        }
    }
    return min;
}