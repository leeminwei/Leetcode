char* reverseWords(char* s) {
    char* s_copy = strdup(s);
    if (s_copy == NULL) return NULL;

    int len = strlen(s_copy);
    char* arr = malloc((len + 1) * sizeof(char));
    if (arr == NULL) {
        free(s_copy);
        return NULL;
    }

    char* token = strtok(s_copy, " ");
    if (token == NULL) {
        arr[0] = '\0';
        free(s_copy);
        return arr;
    }

    int position = len;
    while (token != NULL) {
        int size = strlen(token);
        position -= size;
        strncpy(arr + position, token, size);

        token = strtok(NULL, " ");
        if (token != NULL) {
            position--;
            arr[position] = ' ';
        }
    }

    memmove(arr, arr + position, len - position);
    arr[len - position] = '\0';
    free(s_copy);
    return arr;
}