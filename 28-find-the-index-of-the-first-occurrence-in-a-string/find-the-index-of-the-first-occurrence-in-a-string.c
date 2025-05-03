int strStr(char* haystack, char* needle) {
    int nsize = strlen(needle);
    int hsize = strlen(haystack);
    for(int i=0 ; i<hsize ; i++){
        int check = strncmp(haystack+i,needle,nsize);
        if(check == 0)
            return i;
    }
    return -1;
}