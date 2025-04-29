int integerReplacement(int n) {
    int count = 0;
    long num = n;
    while(num!=1){
        if(num%2==0){
            num/=2;
            count++;
        }
        //如果num的值是3,5,9,13這種,那num-1會是最短路徑
        else if(num==3||num%4==1){
            num = num-1;
            count++;
        }
        //如果num是num%4==3這種,那num+1會是最短路徑
        else{
            num = num+1;
            count++;
        }
        
    }
    return count;
}