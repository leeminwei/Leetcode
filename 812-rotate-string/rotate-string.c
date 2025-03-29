bool rotateString(char* s, char* goal) {
    char number;
    int ret;
    int size = strlen(s);
    printf("size = %d\n",size);
    if(size > strlen(goal))
        return false;
    for(int i=0 ; i<size ; i++){
        int count = 0;
        number = s[0];
        while(count<(size-1)){
            s[count] = s[count+1];
            count++;
        }
        s[size-1] = number;
        count++;
        printf("%s\n",s);
        ret = strcmp(s,goal);
        if(ret == 0)
            return true;  
    }
    return false;
}