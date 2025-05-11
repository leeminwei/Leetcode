char hash_table(int s){
    switch(s)
    {
        case 10 : return 'a';
        case 11 : return 'b';
        case 12 : return 'c';
        case 13 : return 'd';
        case 14 : return 'e';
        case 15 : return 'f';
        default : return '0';
    }
}
char* toHex(int num) {
    if(num == 0) return "0";
    unsigned int answer = num;
    int number = 0;
    char* arr = malloc(32*sizeof(char));
    int index = 0;
    char letter;
    while(answer>=1){
        number = answer%16;
        if(number>=10){
            letter = hash_table(number);
        }
        else{
            letter = number+'0';
        }
        arr[index++] = letter;
        answer/=16;
    }
    arr = realloc(arr,(index+1)*sizeof(char));
    char* result = malloc((index+1)*sizeof(char));
    int idx = 0;
    for(int i=index-1 ; i>=0 ; i--){
        result[idx++] = arr[i];
    }
    result[idx] = '\0';
    return result;
}