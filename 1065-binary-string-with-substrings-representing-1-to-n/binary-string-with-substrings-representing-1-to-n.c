bool mystr(const char* s, const char* pattern){
    int s_len = strlen(s);
    int p_len = strlen(pattern);
    for (int i=0 ; i<s_len ; i++) {
        char* temp = (char*)malloc((s_len+1) * sizeof(char));
        int index = 0;
        for (int j=i ; j<s_len ; j++) {
            temp[index++] = s[j];
            temp[index] = '\0';
            if (strcmp(pattern, temp) == 0) {
                return true;
            }
        }
    }
    return false;
}

void myitoa(int num, char* buffer, int base){
    int i = 0;
    if (num == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    while (num > 0) {
        int digit = num % base;
        buffer[i++] = digit + '0';
        num /= base;
    }
    buffer[i] = '\0';

    // 字串是反過來的，要翻轉
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }
}   

bool queryString(char* s, int n) {
    char buffer[1005];
    bool answer = false;
    for (int i=1 ; i<=n ; i++) {
        myitoa(i, buffer, 2);
        answer = mystr(s, buffer);
        if (answer == false) {
            return false;
        }
    }
    return true;
}