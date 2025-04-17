int numberOfSteps(int num) {
    int count = 0;
    if(num==0) return 0;
    while(num>0){
        if(num%2!=0){
            num = num-1;
            count = count+1;
        }
        num = num/2;
        count = count+1;
    }
    return count-1;
}