int countone(int a){
    int count = 0;
    while(a){
        a&=(a-1);
        count++;
    }
    return count;
}

int hammingDistance(int x, int y) {
    int xor = 0;
    xor = x^y;
    int answer = countone(xor);
    return answer;
}