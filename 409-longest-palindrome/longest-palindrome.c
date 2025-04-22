int longestPalindrome(char* s) {
    int freq[256] = {0};
    int origin = strlen(s);
    for(int i=0 ; i<strlen(s) ; i++){
        freq[s[i]]++;
    }
    int size = strlen(s);
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ; j++){
            if(s[i]==s[j]){
                for(int k=j ; k<size-1 ; k++){
                    s[k] = s[k+1];
                }
                j--;
                size--;
            }
        }
    }
    int count = 0;
    for(int i=0 ; i<size ; i++){
        if(freq[s[i]]%2 == 0){
            count = count + freq[s[i]];
        }
        else if(freq[s[i]]==1){
            count = count;
        }
        else{
            count = count + freq[s[i]]-1;
        }
    }
    if (count < origin)
        return count+1;
    else
        return count;
}