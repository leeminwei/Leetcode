int findComplement(int num) {
    char* arr = (char*)malloc(1*sizeof(char));
    int size = 0;
    int count = 0;
    char number;
    while(num>=1){
        arr = (char*)realloc(arr,(size+1)*sizeof(char));
        arr[size] = num%2 +'0';
        //補數 or 可以寫成arr[i] = (arr[i] == '0') ? '1' : '0';
        if(arr[size]=='0')
            arr[size]='1';
        else
            arr[size]='0';
        size++;
        num = num/2;
    }
    /*
    for (int i = 0; i < size; i++) {
        arr[i] = ~arr[i];
    }
    */
    for(int i=size-1 ; i>=0 ; i--){
        count = count*2 + (arr[i]-'0');
    }
    return count;
}