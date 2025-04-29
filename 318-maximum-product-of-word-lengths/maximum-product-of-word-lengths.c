int bitmask(char* s){
    int size = strlen(s);
    int arr = 0;
    for(int i=0 ; i<size ; i++){
        arr |= 1<<(s[i]-'a');
    }
    return arr;
}
int maxProduct(char** words, int wordsSize) {
    int max_len = 0;
    int len = 0;
    for(int i=0 ; i<wordsSize ; i++){
        for(int j=i+1 ; j<wordsSize ; j++){
            if((bitmask(words[i])&bitmask(words[j]))==0){
                len = strlen(words[i])*strlen(words[j]);
                if(len>max_len)
                    max_len = len;
            }
        }
    }
    return max_len;
}