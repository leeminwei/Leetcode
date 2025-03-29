bool isPalindrome(int x) {
    int number = x;
    long tmp=0; 
    if(x<0)
        return false; 
    while(1){
        tmp=(tmp*10 + x%10);
		x=x/10;
        if(x==0 && tmp == number){
            return true;
        }
        else if(x==0)
            return false;
    }
}