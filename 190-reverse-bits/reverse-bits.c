uint32_t reverseBits(uint32_t n) {
    int answer = 0;
    int bits[32];
    for(int i = 0; i < 32; i++){
        bits[i] = n%2;
        n/=2;
        printf("%d\n",bits[i]);
    }
    for(int i = 0; i < 32; i++){
        answer += bits[i] * pow(2, 31-i);
    }

    return answer;
}