int myAtoi(char* s) {
    int size = strlen(s);
    long long int sum = 0;
    int check = 0; //用來判斷是否遇到正負號或數字了
    int sign = 1;
    for (int i=0 ; i<size ; i++) {
        if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9) {
            sum = sum * 10 + (s[i] - '0');
            check = 1;
            if (sign * sum >= INT_MAX) {
                return INT_MAX;
            }
            else if (sign * sum <= INT_MIN) {
                return INT_MIN;
            }
        }
        else if ((s[i] - '0') > 9 || (s[i] - '0') < 0) {
            if (s[i] == ' ' && check == 0) 
                continue;
            else if (s[i] == '-' && check == 0) {
                sign = -1;
                check = 1;
            }
            else if (s[i] == '+' && check == 0) {
                sign = 1;
                check = 1;
            }
            else
                break;
        }
    }
    return sign * sum;
}