int xorOperation(int n, int start) {
    int* arr = (int*)malloc( n * sizeof(int));
    for(int i=0 ; i<n ; i++){
        arr[i] = start + 2*i;
    }
    int answer = 0;
    for(int i=0 ; i<n ; i++){
        answer^=arr[i];
        //printf("%d\n",arr[i]);
    }
    return answer;
}