char* reverse(char*s,int start,int end){
    int size = end-start+1;
    char* arr = malloc(size*sizeof(char));
    int number = 0;
    for(int i=end ; i>=start ; i--){
        arr[number++] = s[i];
    }
    for(int i=0 ; i<size ; i++){
        s[start+i] = arr[i];
    }
    free(arr);
    return s;
}
char* reverseWords(char* s) {
    int size = strlen(s);
    printf("%d\n",size);
    char* arr = malloc(size*sizeof(char));
    int number = 0;
    int start = 0;
    for(int i=0 ; i<size ; i++){
        if(s[i]==' '){
            s = reverse(s,start,i-1);
            start = (i+1);
        }
    }
    s = reverse(s,start,size-1);
    return s;
}