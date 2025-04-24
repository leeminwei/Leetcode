int findmaxfreq(int* array,int start,int end){
    int *freq = calloc(50000,sizeof(int));
    for(int i=start ; i<end ; i++){
        freq[array[i]]++;
    }
    int max_freq = 0;
    int current_freq = 0;
    for(int i=start ; i<end ; i++){
        current_freq = freq[array[i]];
        if(current_freq > max_freq){
            max_freq = current_freq;
        }
    }
    free(freq);
    return max_freq;
}

int findShortestSubArray(int* nums, int numsSize) {
    int freq[50000] = {0};       // 儲存出現次數
    int first[50000];            // 記錄最早出現位置
    int maxFreq = 0;
    int minLen = numsSize;

    for (int i=0 ; i<numsSize ; i++) {
        int index = nums[i];
        if(freq[index]==0){      //如果這個元素第一次出現
            first[index] = i;    //記錄這個元素出現的第一個位置
        }
        freq[index]++;
        if (freq[index] > maxFreq) { //持續更新最短長度
            maxFreq = freq[index];
            minLen = i - first[index] + 1;
        }
        else if (freq[index] == maxFreq) {  //比較如果最大頻率相等的狀況出現
            int len = i - first[index] + 1;
            if (len < minLen)
                minLen = len;
        }
    }
    return minLen;   
}

//Time Limit
/*
int max_nums = findmaxfreq(nums,0,numsSize);
    printf("%d\n",max_nums);
    int short_len = numsSize;
    int start = 0;
    int end = numsSize - 1; //代表陣列的最後一個元素
    int len = 0;
    int shortest_len = numsSize;
    for(int i=start ; i<=end ; i++){
        for(int j=i ; j<=end ; j++){
            int sub_freq = findmaxfreq(nums,i,j+1);
            len = j-i+1;
            printf("i=%d,j=%d,len=%d\n",i,j,len);
            if(sub_freq == max_nums && len<shortest_len){
                shortest_len = len;
            }
        }
    }
    return shortest_len;
*/