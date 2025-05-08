char* delete(char* s){
    int size = strlen(s);
    for (int i = 0; i < size; i++) {
        if (s[i] == '#' && i > 0) {
            // 將前一個字元和 '#' 一起刪掉
            for (int j = i - 1; j + 2 < size; j++) {
                s[j] = s[j + 2];
            }
            size -= 2;
            i -= 2;  // 回到前一個位置再檢查
            if (i < -1) i = -1;  // 防止索引變負
        } else if (s[i] == '#') {
            // i == 0 的情況，只有一個 #
            for (int j = i; j + 1 < size; j++) {
                s[j] = s[j + 1];
            }
            size--;
            i--;  // 回到前一個位置
        }
    }
    s[size] = '\0';
    return s;
}
bool backspaceCompare(char* s, char* t) {
    s = delete(s);
    t = delete(t);
    int ssize = strlen(s);
    int tsize = strlen(t);
    if(ssize!=tsize) return false;
    else{
        for(int i=0 ; i<ssize ; i++){
            if(s[i]!=t[i])
                return false;
        }
    }
    return true;   
}