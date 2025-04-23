int findLHS(int* nums, int numsSize) {
    int *freq = calloc(numsSize,sizeof(int));
    // sort from min to max
    int cmp(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    /*
    for(int i=0 ; i<numsSize ; i++){
        for(int j=i+1 ; j<numsSize ; j++){
            if(nums[i] > nums[j]){
                int current = nums[i];
                nums[i] = nums[j];
                nums[j] = current;
            }
        }
    }
    */
    for(int i=0 ; i<numsSize ; i++){
        freq[i] = nums[i];
    }
    int max = 0;
    for(int i=0 ; i<numsSize ; i++){
        int count = 1;
        int number = i;
        int len = 0;
        //用來數當前重複的元素有幾個
        while(number + 1 < numsSize && freq[number]==freq[number+1]){
            count++;
            number++;
        }
        //如果遇到下一個元素的值差"1"  那就開始數下一個元素重複幾個
        if(number + 1 < numsSize && freq[number+1]-freq[i]==1){
            int next_value = number+1;
            int next_count = 1;
            while(next_value + 1 < numsSize && freq[next_value]==freq[next_value+1]){
                next_count++;
                next_value++;
            }
            len = count + next_count;
        }
        if(len>max)
            max = len;
    }
    return max;
}
/*  Time Limit
    int min = nums[0];
    int max = nums[0];
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]<min)
            min = nums[i];
        else if(nums[i]>max)
            max = nums[i];
    }
    int *freq = calloc((max-min+1),sizeof(int));
    for(int i=0 ; i<numsSize ; i++){
        freq[nums[i]-min]++;
    }
    int max_len = 0;
    for(int i=min ; i<max ; i++){
        int count = 0;
        int len = 0;
        if(freq[i-min]!=0 && freq[i+1-min]!=0){
            len = freq[i-min] + freq[i+1-min];
        }
        if(len > max_len)
            max_len = len;
    }
    return max_len;
*/