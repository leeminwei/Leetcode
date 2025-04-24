int divide(int dividend, int divisor) {
    long int answer = 0;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if(dividend<0&&divisor>0 || dividend>0&&divisor<0){
        answer = -labs((long int) dividend)/labs((long int) divisor);
    }
    else if(dividend>0&&divisor>0 || dividend<0&&divisor<0){
        answer = labs((long int) dividend)/labs((long int) divisor);
    }
    return (int)answer;
}