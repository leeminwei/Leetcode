bool detectCapitalUse(char* word) {
    int number = strlen(word);
    int count = 0;
    for(int i=0 ; i<number ; i++){
        printf("%d\n",word[i]);
    }
    if(word[0]>90){
        for(int i=1 ; i<number ; i++){
            if(word[i]<91)
                return false;
        }   
    }
    else{
        for(int i=1 ; i<number ; i++){
            if(word[i]>90)
                count++;
        }
    }
    if(count!=(number-1)&&count!=0){
        return false;
    }
    else
        return true;
}