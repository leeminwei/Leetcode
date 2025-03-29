bool isSubsequence(char* s, char* t) {
    size_t i = 0;  // Pointer for t
    size_t j = 0;  // Pointer for s
    
    if (strlen(s) == 0)
        return true;  // An empty string is always a subsequence
    
    while (t[i] != '\0') {
        if (t[i] == s[j]) {
            j++;  // Move to the next character in s
        }
        if (j == strlen(s))
            return true;  // Found all characters of s in order
        i++;
    }
    return false;  // s was not found as a subsequence in t
}
    /*
    if(strlen(s) == strlen(t)){
        int number;
        number = strcmp(s, t);
        printf("%d\n", strcmp(s, t));
        if(number == 0)
          return true;
        else 
            return false;
    }
    
    char *position;
    char *position_next;
    int check = 0;
    int number = 0;
    for(int i=0 ; i<strlen(s) ; i++){
        position = strchr(t, s[i]);
        position_next = strchr(t, s[i+1]);
        number = position - t;
        check = position_next - t;
        if(position > position_next){
            return false;
        }
        else if(position == NULL || position_next == NULL){
            return false;
        }
        /*
        else
            for(int j = check ; j<strlen(t) ; j++){
                t[j] = t[j+1];
            }
            for(int j = number ; j<strlen(t) ; j++){
                t[j] = t[j+1];
            }
            i = i-2;
            
    }
    return true;
    */
