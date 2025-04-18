int bitmask(const char* a, int start, int end){
    int lower_mask = 0;
    int upper_mask = 0;
    for(int i=start ; i<=end; i++){
        if(a[i] >= 'a' && a[i] <= 'z'){
            lower_mask |= 1<<(a[i] - 'a');
        }
        else if(a[i] >= 'A' && a[i] <= 'Z'){
            upper_mask |= 1<<(a[i] - 'A');
        }
    }
    return lower_mask == upper_mask; 
}
char* longestNiceSubstring(char* s) {
    int start = 0;
    int end = 0;
    int max = 0;
    for(int i=0 ; i<strlen(s) ; i++){
        for(int j=i ; j<strlen(s) ; j++){
            if(bitmask(s,i,j) && j-i+1 > max){
                start = i;
                end = j;
                max = j-i+1;
            }
        }
    }
    char* arr = (char*)malloc((max+1)*sizeof(char));
    strncpy(arr,s+start,max);
    arr[max] = '\0';
    return arr;
}