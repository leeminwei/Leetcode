bool areOccurrencesEqual(char* s) {
    int* freq = calloc(256,sizeof(int));
    int size = strlen(s);
    for(int i=0 ; i<size ; i++){
        freq[s[i]]++;
    }
    for(int i=0 ; i<size-1 ; i++){
        if(freq[s[i]]!=freq[s[i+1]])
            return false;
    }
    return true;
}