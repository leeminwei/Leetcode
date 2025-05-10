#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    char* token;
    char* s_copy = strdup(s);  // 複製一份，避免 strtok 修改原始字串
    if (s_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    int len = strlen(s_copy);
    char* arr = malloc((len + 1) * sizeof(char));
    if (arr == NULL) {
        perror("malloc");
        free(s_copy);
        return NULL;
    }

    token = strtok(s_copy, " ");
    if (token == NULL) {
        arr[0] = '\0';
        free(s_copy);
        return arr;
    }

    int size = strlen(token);
    int position = len - size;
    strncpy(arr + position, token, size);

    while ((token = strtok(NULL, " ")) != NULL) {
        position--; // 放空格
        arr[position] = ' ';

        size = strlen(token);
        position -= size;
        strncpy(arr + position, token, size);
    }

    // 移動結果到字串開頭
    int shift = position;
    for (int i = 0; i < len - shift; i++) {
        arr[i] = arr[i + shift];
    }
    arr[len - shift] = '\0';

    free(s_copy);
    return arr;
}
