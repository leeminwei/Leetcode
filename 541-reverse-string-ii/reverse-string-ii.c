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
    int point2 = 2*k;
    int point = k;
    int index = 0;
    while(point2<=size){
        s = reverse(s,index,point);
        index += 2*k;
        point2 += 2*k;
        point += 2*k;
    }
    //確認現在的point不會超出size
    int right = point;
    if (right > size)
        right = size;
    s = reverse(s,index,right);
    return s;
}