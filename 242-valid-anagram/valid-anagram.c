bool isAnagram(char* s, char* t) {
    int s_freq[256] = {0};
    int t_freq[256] = {0};
    if(strlen(s)!=strlen(t))
        return false;
    for(int i=0 ; i<strlen(s) ; i++){
        s_freq[s[i]]++;
        t_freq[t[i]]++;
    }
    for(int i=0 ; i<256 ; i++){
        if(s_freq[i]!=t_freq[i])
            return false;
    }
    return true;
}