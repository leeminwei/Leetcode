bool isPowerOfFour(int n) {
    long int number = 1;
    int check = 0;
    int i = 0;
    if(n<0 || n==0)
        return false;
    else if(n==1)
        return true;
    while(number<n){
        number = number*4;
        printf("number = %d\n",number);
        if(number==n)
            return true;
    }
    return false;
}