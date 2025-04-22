bool canConstruct(char* ransomNote, char* magazine) {
    int r_freq[256] = {0};
    int m_freq[256] = {0};
    for(int i=0 ; i<strlen(ransomNote) ; i++){
        r_freq[ransomNote[i]]++;
    }
    for(int i=0 ; i<strlen(magazine) ; i++){
        m_freq[magazine[i]]++;
    }
    for(int i=0 ; i<strlen(ransomNote) ; i++){
        if(r_freq[ransomNote[i]]>m_freq[ransomNote[i]])
            return false;
    }
    return true;
}