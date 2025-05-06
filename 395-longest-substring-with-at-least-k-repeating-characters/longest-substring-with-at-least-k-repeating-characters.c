int longestSubstring(char* s, int k) {
    int size = strlen(s);
    int *freq = calloc(26,sizeof(int));
    for(int i=0 ; i<size ; i++){
        freq[s[i]-'a']++;
    }
    for(int i=0 ; i<size ; i++){
        if(freq[s[i]-'a']>0 && freq[s[i]-'a']<k){
            int left = longestSubstring(strndup(s, i), k); // 前段 [0, i-1]
            int right = longestSubstring(s + i + 1, k);    // 後段 [i+1, end]
            if(right>left)
                return right;
            else
                return left;
        }
    }
    return size;
}
/*
    for(int i=0 ; i<size ; i++){
        for(int j=i ; j<size ; j++){
            count = substring(s,i,j,k);
            if(count>max)
                max = count;
        }
    }
    */