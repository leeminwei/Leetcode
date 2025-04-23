/*
int mask(char*s,int start,int end){  
    int freq[256] = {0};
    for(int i= start ; i<=end ; i++){
        freq[s[i]]++;
    }
    int count = 0;
    for(int i=0 ; i<256 ; i++){
        if(freq[i]>1){
            return 1;
        }
        else if(freq[i]==1){
            count++;
        }
        else
            continue;
    }
    return count;
}
*/
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int max = 0;

    for (int i = 0; i < n; i++) {
        int freq[256] = {0};  // 清空記錄表
        for (int j = i; j < n; j++) {
            if (++freq[(unsigned char)s[j]] > 1)
                break;  // 出現重複就停
            int len = j - i + 1;
            if (len > max)
                max = len;
        }
    }

    return max;
}
    /*
    int max = 0;
    int n = strlen(s);
    for(int i=0 ; i<n; i++){
        int number = 0;
        for(int j=i ; j<n ; j++){
            number = mask(s,i,j);
            if(number>max)
                max = number;
        }
    }
    return max;
}
*/