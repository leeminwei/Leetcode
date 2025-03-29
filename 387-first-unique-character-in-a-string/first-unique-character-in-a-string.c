int firstUniqChar(char* s) {
    int freq[256]={0};
    for(int i=0;i<strlen(s);i++)
    {
        freq[s[i]]++;
    }  
    for(int i=0;i<strlen(s);i++)
    {
        printf("%c的freq = %d\n",s[i],freq[s[i]]);
        if(freq[s[i]]==1)
        {
            return i;
            break;
        }
    }
    return -1;
}
    /*
    int size = strlen(s);
    for(int i=0 ; i<size ; i++){
        int count = 0;
        for(int j=0 ; j<size ; j++){
            if(s[i] == s[j]){
                count++;
            }
        }
        if(count==1){
            return i;
        }
    }
    return -1;
    */
