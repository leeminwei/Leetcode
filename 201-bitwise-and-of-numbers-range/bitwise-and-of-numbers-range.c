int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    while(left<right){
        left = left>>1;     //right shift
        right = right>>1;   //right shift
        count++;
    }
    return left<<count;
}