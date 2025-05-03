bool isPalindrome(char* s) {
    int size = strlen(s);
    char* arr = malloc(size*sizeof(char));
    int number = 0;
    for(int i=0 ; i<size ; i++){
        if(ispunct(s[i])==0 && s[i]!=' '){
            arr[number] = tolower(s[i]);
            number++;
        }        
    }
    arr = realloc(arr,number*sizeof(char));
    for(int i=0 ; i<number ; i++){
        printf("%c",arr[i]);
    }
    int left = 0;
    int right = number-1;
    while(left<right){
        if(arr[left]!=arr[right]){
            free(arr);
            return false;
        }
        left++;
        right--;
    }
    free(arr);
    return true;
}