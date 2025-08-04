bool isValid(char* s) {
    int size = strlen(s);
    char* stack = (char*)malloc(size * sizeof(char));
    int idx = 0;
    for (int i=0; i<size ; i++) {
        if (s[i] == 'a' || s[i] == 'b') {
            stack[idx++] = s[i];
        }
        if (s[i] == 'c' && idx >= 2) {
            if (stack[idx-1] == 'b' && stack[idx-2] == 'a') {
                idx = idx-2;
            }
            else{
                return false;
            }
        }
    }
    if (idx == 0) {
        return true;
    }
    return false;
}