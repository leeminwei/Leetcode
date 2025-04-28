int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    while(left<right){
        left >>= 1;     //right shift
        right >>= 1;   //right shift
        count++;
    }
    return left<<count;
}