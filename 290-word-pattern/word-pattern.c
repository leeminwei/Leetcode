bool wordPattern(char* pattern, char* s) {
    char *arr = strtok(s, " ");
    char *p_char[1001] = {0};
    char *s_char[3001] = {0};
    int count = 0;
    //將s透過" "拆成多個字串arr，並將這些字串存在s_char陣列中
    while(arr!=NULL){
        s_char[count] = arr;
        arr = strtok(NULL, " ");
        count++;
    }
    if(count!=strlen(pattern)) return false;  //如果兩個字串長度不一樣 return false
    for(int i=0 ; i<strlen(pattern) ; i++){
        char letter = pattern[i];
        char* word = s_char[i];

        // 如果 pattern[i] 第一次出現
        if (p_char[letter] == NULL) {
            // 先檢查這個 word 有沒有已經對應過其他 letter
            for (int j = 0; j < 256; j++) {
                if (p_char[j] != NULL && strcmp(p_char[j], word) == 0)
                    return false;
            }
            p_char[letter] = word;
        }
        // 如果這個字母已經有對應字串，就檢查已經對應的字串是否與現在要被對應的字串一樣
        else {
            if (strcmp(p_char[letter], word) != 0)
                return false;
        }
    }
    return true;
}