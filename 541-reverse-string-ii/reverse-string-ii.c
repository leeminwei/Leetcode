char* reverse(char* s, int start, int end) {
    int size = end - start;
    char* arr = malloc(size * sizeof(char));
    int number = 0;

    for (int i = end - 1; i >= start; i--) {
        arr[number++] = s[i];
    }

    for (int i = 0; i < size; i++) {
        s[start + i] = arr[i];
    }

    free(arr);
    return s;
}

char* reverseStr(char* s, int k) {
    int size = strlen(s);
    int i = 0;
    int end = 0;

    while (i < size) {
        if (i + k < size)
            end = i + k;
        else
            end = size;

        s = reverse(s, i, end);
        i += 2 * k;
    }

    return s;
}