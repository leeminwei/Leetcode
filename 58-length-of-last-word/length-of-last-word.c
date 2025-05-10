int lengthOfLastWord(char* s) {
    char* token;
    int size = strlen(s);
    token = strtok(s," ");
    int token_size=0;
    while(token!=NULL){
        printf("%s",token);
        token_size = strlen(token);
        token = strtok(NULL," ");
    }
    return token_size;
}