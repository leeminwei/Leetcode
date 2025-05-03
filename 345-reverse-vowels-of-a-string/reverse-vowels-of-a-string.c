char* reverseVowels(char* s) {
    char arr[] = {'a','e','i','o','u','A','E','I','O','U','\0'};
    int size = strlen(s);
    int left = 0;
    int right = size-1;
    while(left<right){
        if(strchr(arr,s[left])==NULL){
            left++;
        }
        else if(strchr(arr,s[right])==NULL){
            right--;
        }
        else{
            char check = s[left];
            s[left] = s[right];
            s[right] = check;
            left++;
            right--;
        }
    }
    return s;
}