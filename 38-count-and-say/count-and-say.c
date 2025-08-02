char* countAndSay(int n) {
    char* arr = (char*)malloc(2 * sizeof(char));
    arr[0] = '1';
    arr[1] = '\0';
    if (n == 1) {
        return arr;
    }
    int index = 1;
    for (int i=1 ; i<n ; i++) {
        char* buffer = (char*)malloc(INT_MAX * sizeof(char)); //用來存第n次的count和num
        int buffer_idx = 0;
        int j = 0;
        while (j < strlen(arr)) {
            int count = 1;
            while (arr[j] == arr[j+1]) {
                count++;
                j++;
            }
            buffer[buffer_idx++] = count + '0';
            buffer[buffer_idx++] = arr[j];
            j++;
        }
        buffer[buffer_idx] = '\0';
        arr = realloc(arr, (buffer_idx+1) * sizeof(char));
        strcpy(arr, buffer);
        free(buffer);
    }
    return arr;
}