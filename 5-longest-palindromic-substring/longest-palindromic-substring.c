int middlecheck(char* s,int start,int end){
    int len = 0;
    int left = start;
    int right = end;

    while (left < right) {
        if (s[left] != s[right]) {
            return 0;  // 不是回文
        }
        left++;
        right--;
    }

    len = end - start + 1;
    return len;  // 是回文，回傳長度
}
char* longestPalindrome(char* s) {
    int size = strlen(s);
    int len = 0;
    int max = 0;
    int start = 0;
    int end = 0;
    for(int i=0 ; i<size ; i++){
        for(int j=i ; j<size ; j++){
            len = middlecheck(s,i,j);
            if(len>max){
                max = len;
                start = i;
                end = j;
            }
        }
    }
    char *arr = malloc((max+1)*sizeof(char));
    strncpy(arr,s+start,max);
    arr[max] = '\0';
    return arr;
}