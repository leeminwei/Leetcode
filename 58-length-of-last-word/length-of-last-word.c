int lengthOfLastWord(char* s) {
    char* token;
    int size = strlen(s);
    char* arr = malloc(size*sizeof(char));
    int index = 0;
    token = strtok(s," ");
    int token_size=0;
    while(token!=NULL){
        printf("%s",token);
        token_size = strlen(token);
        token = strtok(NULL," ");
    }
    /*
    for(int i=0 ; i<token_size ; i++){
        arr[index++] = token[i];
    }
    */
    return token_size;
}