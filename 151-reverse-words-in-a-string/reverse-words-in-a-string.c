char* reverseWords(char* s) {
    char* token;
    char* s_copy = strdup(s);
    int len = strlen(s_copy);
    printf("%d\n",len);
    char* arr = malloc((len + 1)*sizeof(char));
    if (s_copy == NULL) {
        perror("strdup");
        return NULL;
    }
    token = strtok(s_copy," ");
    if (token == NULL) {
        arr[0] = '\0';
        free(s_copy);
        return arr;
    }
    int size = strlen(token);
    int position = len-size;
    strncpy(arr+position,token,size);
    arr[len] = '\0';
    while(token!=NULL){
        if(position<=0)
            break;
        position--;
        arr[position] = ' ';
        token = strtok(NULL," ");
        if (token != NULL) { // 檢查 token 是否為 NULL
            size = strlen(token);
            position -= size;
            printf("%d\n",position);
            strncpy(arr+position,token,size);
        }
    }
    //判斷陣列的第一個元素是不是字母或數字，如果不是就進行未移
    while (!isalnum(arr[0])) {
        memmove(arr, arr + 1, strlen(arr));
    }
    int shift = strlen(arr);
    arr[shift] = '\0';
    free(s_copy);
    return arr;
}