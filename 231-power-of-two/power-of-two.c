bool isPowerOfTwo(int n) {
    long long count = 1;
    if(n==1){
        return true;
    }   
    for(int i=0 ;i<33 ; i++){
        count = count*2;
        if(n==count){
            return true;
        }
    }
    return false;
}