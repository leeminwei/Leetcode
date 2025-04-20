int square(int a){
    int sum = 0;
    while(a>0){
        int digit = a%10;
        sum = sum + (digit*digit);
        a = a/10;
    }
    return sum;
}
bool isHappy(int n) {
    int slow = n, fast = square(n);
    printf("%d\n",fast);
    while (fast != 1 && slow != fast) {
        slow = square(slow);
        fast = square(square(fast));
    }
    return fast == 1;
}