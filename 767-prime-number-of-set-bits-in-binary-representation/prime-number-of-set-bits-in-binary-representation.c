int countone(int n){
    int count = 0;
    while(n!=0){
        n&=(n-1);
        count++;
    }
    return count;
}
int count(int n){
    int bit = 0;
    int number = 0;
    while(n>=1){
        number = n%2;
        bit++;
        n/=2;
    }
    return bit;
}
bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true; // 2 和 3 是質數
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // 先排除能被 2 或 3 整除的數
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int countPrimeSetBits(int left, int right) {
    int number = 0;
    int one = 0;      //紀錄整數袃二進制中有多少個1
    int totalbit = 0; //紀錄整數在二進制中有多少的位元
    int answer = 0;   //用來數有幾個符合
    for(int i=left ; i<=right ; i++){
        number = i;
        one = countone(number);
        printf("one = %d\n",one);
        if(isprime(one)==true){
            answer++;
        }
    }
    return answer;
}