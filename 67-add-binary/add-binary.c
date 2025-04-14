char* addBinary(char* a, char* b) {
    int lengthb = strlen(b);
    int lengtha = strlen(a);
    int max;
    int min;
    int number = 0;
    if(lengthb>lengtha){
        max = lengthb;
        min = lengtha;
    }
    else{
        max = lengtha;
        min = lengthb;
    }
    char* arr = (char*)malloc((max+2)*sizeof(char));
    memset(arr, '0', max + 1);
    arr[max + 1] = '\0';
    int i = lengtha-1;
    int j = lengthb-1;
    int size = max;
    while(i>=0 || j>=0){
        int counta = (i >= 0) ? a[i--] - '0' : 0;
        int countb = (j >= 0) ? b[j--] - '0' : 0;
        int count = (arr[size]-'0')+counta + countb;
        if(count>=2){
            arr[size] = count%2 + '0';
            arr[size-1] = '1';
        }
        else{
            arr[size] = count + '0';
        }
        size--;
    }
    if (arr[0] == '0') {
        return arr + 1;
    }
    return arr;
}
/*
int lengtha = strlen(a);
    int lengthb = strlen(b);
    int counta = 0;
    int countb = 0;
    int count = 0;
    int answer = 0;
    for(int i=0 ; i<lengtha ; i++){
        counta = counta*2 + (a[i]-'0');
    }
    for(int i=0 ; i<lengthb ; i++){
        countb = countb*2 + (b[i]-'0');
    }
    
    count = counta + countb;
    printf("%d\n",count);
    char* arr = (char*)malloc(32*sizeof(char));
    arr[32] = '\0';
    for(int i=31 ; i>=0 ; i--){
        arr[i] = count%2 + '0';
        count = count/2;
        if(count==0){
            break;
        }
    }
    int size = strlen(arr);
    for(int i=0 ; i<size-1 ; i++){
        if(arr[i]=='0'){
            for(int j=i ; j<size-1 ; j++){
                arr[j] = arr[j+1];
            }
            size--;
            i--;
        }
        else
            break;
    }
    
    printf("answer = %d\n",answer);
    return arr;
*/
/*
for(int i=min-1 ; i>=0 ; i--){
        number = (arr[i-1]-'0') + (a[i]-'0') + (b[i]-'0');
        if(number>=2){
            arr[i] = number%2;
            arr[i-1] = '1';
        }
        else
            arr[i] = number + '0';
    }
    for(int i=0 ; i<max-min ; i++){
        if(max == lengtha){
            arr[i] = a[i];
        }
        else
            arr[i] = b[i];
    }
    return arr;
*/