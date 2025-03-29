int countSegments(char* s) {
    if(s==""){
            return 0;
        }
    int c=0;
    for(int i=0;i<strlen(s);i++){
        if((s[i] != ' ') && ((s[i+1] == ' ')||(s[i+1]=='\0'))){
                c++;
        }
    }
    return c;
}