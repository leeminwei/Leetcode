int newsize(char* s){
    int len = strlen(s);
    int i = 0;
    int* arr = (int*)malloc(len*sizeof(int));
    char* token;
    token = strtok(s, ".");
    while (token!=NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    arr = realloc(arr, i*sizeof(int));
    return i;
}
int* convert(char* s){
    int len = strlen(s);
    int i = 0;
    int* arr = (int*)malloc(len*sizeof(int));
    char* token;
    token = strtok(s, ".");
    while (token!=NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    arr = realloc(arr, i*sizeof(int));
    return arr;
}
int compareVersion(char* version1, char* version2) {
    char* v1_copy1 = strdup(version1);
    char* v1_copy2 = strdup(version1);
    char* v2_copy1 = strdup(version2);
    char* v2_copy2 = strdup(version2);

    int len1 = newsize(v1_copy1);
    int len2 = newsize(v2_copy1);
    int* arr1 = convert(v1_copy2);
    int* arr2 = convert(v2_copy2);
    if (len1 > len2) {
        arr2 = realloc(arr2, len1*sizeof(int));
        for(int i=0 ; i<len1 ; i++) {
            if (i>=len2) {
                arr2[i] = 0;
            }
            if (arr1[i]>arr2[i]){
                return 1;
            }
            else if (arr1[i]<arr2[i]) {
                return -1;
            }
        }
        return 0;
    }
    else if (len1 == len2) {
        for (int i=0 ; i<len1 ; i++) {
            if (arr1[i]>arr2[i]) {
                return 1;
            }
            else if (arr1[i]<arr2[i]) {
                return -1;
            }
        }
        return 0;
    }
    else{
        arr1 = realloc(arr1, len2*sizeof(int));
        for(int i=0 ; i<len2 ; i++) {
            if (i>=len1) {
                arr1[i] = 0;
            }
            if (arr1[i]>arr2[i]){
                return 1;
            }
            else if (arr1[i]<arr2[i]) {
                return -1;
            }
        }
        return 0;
    }
    return 0;
}