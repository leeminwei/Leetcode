char* reversePrefix(char* word, char ch) {
    int size = strlen(word);
    int number = strlen(word);
    int count = 0;
    int record = 0;
    int check = 0;
    char array[number]={};
    char *answer = (char*)calloc((size + 1) ,sizeof(char));
    //取出word遇到ch前的所有字元
    for(int i=0 ; i<size ; i++){
        if(word[i] != ch){
            array[count] = word[i];
            count++;
        }
        else{
            check=1;
            array[count] = ch;
            count++;
            break;
        }
    }
    /*array陣列為word遇到ch前的所有字元
    for(int i=0 ; i<count ; i++){
        printf("%c\n",array[i]);
    }
    */
    printf("check = %d\n",check);

    //answer陣列為array顛倒的結果abcd → dcba
    for(int i=count ; i>0 ; i--){
        answer[record] = array[i-1];
        record++;
    }
    //存放word中ch後的字元
    for(int i=record ; i<number ; i++){
        answer[i] = word[i];
    }
    for(int i=0 ; i<number ; i++){
        printf("%c",answer[i]);
    }
    //如果word中有ch字元 return answer陣列
    if(check == 1)
        return answer;
    else
        return word;
}