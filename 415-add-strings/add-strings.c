int max(int a,int b){
    if (a>b) return a;
    else return b;
}
char* addStrings(char* num1, char* num2) {
    int size = strlen(num1)-1;
    int size2 = strlen(num2)-1;
    int maxnum = max(size,size2);
    int carry = 0; //用來判斷進位
    int sum = 0;
    char* arr = malloc((maxnum+2)*sizeof(char)); //+2是因為有進位問題和'\0'
    int index = 0;
    int n1,n2 = 0;
    while(size>=0 || size2>=0 || carry==1){
        if(size>=0){
            n1 = num1[size]-'0';
            size--;
        }
        else{
            n1 = 0;
        }
        if(size2>=0){
            n2 = num2[size2]-'0';
            size2--;
        }
        else{
            n2 = 0;
        }
        sum = n1+n2+carry;
        int digit = sum%10;
        arr[index++] = digit+'0';
        //printf("%c",arr[index-1]);
        carry = sum/10;
        //printf("carry = %d\n",carry);
    }
    arr = realloc(arr,(index+1)*sizeof(int));
    arr[index] = '\0';
    printf("%s",arr);
    int position = index-1;
    for(int i=0 ; i<index/2 ; i++){
        int number = arr[i];
        arr[i] = arr[position];
        arr[position] = number;
        position--;
    }
    /*
    char* result = malloc((index+1)*sizeof(char));
    int idx = 0;
    for(int i=index-1 ; i>=0 ; i--){
        result[idx++] = arr[i];
    }
    result[index] = '\0';
    */
    return arr;
}
/*
int size = strlen(num1);
    int size2 = strlen(num2);
    long long int count = 0;
    long long int count2 = 0;
    for(int i=0 ; i<size ; i++){
        //printf("%d\n",num1[i]-'0');
        count = count*10+(num1[i]-'0');
    }
    for(int i=0 ; i<size2 ; i++){
        //printf("%d\n",num2[i]-'0');
        count2 = count2*10+(num2[i]-'0');
    }
    long long int sum = count + count2;
    printf("sum = %d\n",sum);
    int* arr = malloc(64*sizeof(int));
    int index = 0;
    if(sum==0) return "0";
    while(sum>=1){
        int number = sum%10;
        arr[index++] = number;
        sum/=10;
    }
    arr = realloc(arr,index*sizeof(int));
    for(int i=0 ; i<index ; i++){
        printf("%d",arr[i]);
    }
    char* result = malloc((index+1)*sizeof(char));
    int idx = 0;
    for(int i=index-1 ; i>=0 ; i--){
        result[idx++] = arr[i]+'0';
    }
    result[index] = '\0';
    return result;
*/
