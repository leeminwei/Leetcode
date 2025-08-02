#define module 1000000007

int concatenatedBinary(int n){
    long long int sum = 0;
    int len = 0;
    for (int i=1 ; i<=n ; i++) {
        //如果是2的倍數，二進制長度就+1
        if ((i & (i - 1)) == 0) 
            len++;
        //公式 = 目前十進制左移二進制長度位再加i
        sum = ((sum << len) + i) % module;
    }
    return sum;
}