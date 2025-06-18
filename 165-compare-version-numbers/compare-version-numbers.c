int* convert(char* s, int* size){
    int len = strlen(s);
    int i = 0;
    int* arr = (int*)malloc(len*sizeof(int));
    char* token;
    token = strtok(s, ".");
    while (token!=NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    *size = i;
    arr = realloc(arr, i*sizeof(int));
    return arr;
}
int compareVersion(char* version1, char* version2) {
    int len1 = 0;
    int len2 = 0;
    int* arr1 = convert(version1, &len1);
    int* arr2 = convert(version2, &len2);
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