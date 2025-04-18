int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int allow_mask = 0;
    for(int i=0 ; i<strlen(allowed) ; i++){
        allow_mask |= 1<<abs(allowed[i]-'a');
        //printf("%d\n",allow_mask);
    }
    int count = 0;
    for(int i=0 ; i<wordsSize ; i++){
        int words_mask =0;
        for(int j=0 ; j<strlen(words[i]) ; j++){
            words_mask |= 1<<abs(words[i][j]-'a');
        }
        if((words_mask & allow_mask) == words_mask){
                count++;
            }
    }
    return count;
}