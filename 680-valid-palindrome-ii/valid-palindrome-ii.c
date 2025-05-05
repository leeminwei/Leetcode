bool check(char* s, int left, int right){
    int size = strlen(s);
    while(left<right){
        if(s[left]!=s[right]){
                return false;
        }
        left++;
        right--;
    }
    return true;
}
bool validPalindrome(char* s) {
    int size = strlen(s);
    int left = 0;
    int right = size-1;
    while(left<right){
        if(s[left]!=s[right]){
           if(check(s,left+1,right)==false && check(s,left,right-1)==false)
                return false;
           else
                return true;
        }
        left++;
        right--;
    }
    return true;
}