int bitwiseComplement(int n) {
    char* arr = (char*)malloc(1*sizeof(char));
    int size = 0;
    int number = 0;
    int count = 0;
    if(n==0) return 1;
    while(n>=1){
        arr = (char*)realloc(arr,(size+1)*sizeof(char));
        arr[number] = n%2+'0';
        printf("%c\n",arr[number]);
        if(arr[number]=='0')
            arr[number]='1';
        else
            arr[number]='0';
        n=n/2;
        number++;
        size++;
    }
    for(int i=size-1 ; i>=0 ; i--){
        count = count*2+(arr[i]-'0');
    }
    return count;
}