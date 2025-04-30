int reverse(int x){
    long int number = 0;
    long num = (long)labs(x);  // 避免 INT_MIN 溢位
    while(num!=0){
        number = number*10 + num%10;
        num/=10;
    }
    if(number>INT_MAX || -number<INT_MIN){
        return 0;
    }
    if(x<0)
        return -number;
    else
        return number;
}