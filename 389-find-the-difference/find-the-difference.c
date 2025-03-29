char findTheDifference(char* s, char* t) {
    int size = strlen(s);
    int tsize = strlen(t);
    for(int i=0 ; i<size ; i++){    
        for(int j=0 ; j<tsize ; j++){
            if(s[i]==t[j]){
                for(int k=j ; k<tsize ; k++){
                    t[k] = t[k+1];
                }
                j--;
                tsize--;
                break;
            }
            
        }
    }
    printf("%s",t);
    return *t;
}