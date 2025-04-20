bool hasAlternatingBits(int n) {
    int count = 0;
    int pre_count = 0;
    int check = 0;
    while(n>=1){
        count=n%2;
        if(count == pre_count && check!=0){
            return false;
        }
        n = n/2;
        pre_count = count;
        check++;
    }
    return true;
}