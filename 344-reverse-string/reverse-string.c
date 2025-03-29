void reverseString(char* s, int sSize) {
    int number = 0;
    printf("%d\n",sSize);
    char word;
    char *array = (char*)malloc( sSize * sizeof(char) );
    for(int i=0 ; i<sSize ; i++){
        word = s[i];
        s[i] = s[sSize-1];
        s[sSize-1] = word;
        sSize--;
        if(i == sSize || sSize<i)
            break;
    }
}