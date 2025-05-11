int binaryGap(int n) {
    int count = 0;
    int num = n;
    while(num!=0){
        num&=(num-1);
        count++;
    }
    if(count==1||count==0) return 0;
    int* arr = calloc(32,sizeof(int));
    int index = 0;
    int dis = 0;
    int pre = 0;
    int cur = 0;
    int max_dis = 0;
    while(n>=1){
        int number = n%2;
        arr[index++] = number;
        n/=2;
    }
    for(int i=0 ; i<32 ; i++){
        if(arr[i]==1){
            cur = i+1;
        }
        if(arr[i]==1 && pre!=0)
            dis = abs(cur - pre);
        if(dis>max_dis)
            max_dis = dis;
        pre = cur;
    }
    return max_dis;
}
/*
int first = 0;
    for(int i=0 ; i<32 ; i++){
        if(arr[i]==0){
            first = i;
            printf("first = %d\n",first);
            break;
        }
    }
    int last = 0;
    for(int i=0 ; i<32 ; i++){
        if(arr[i]==0){
            last = i;
            printf("last = %d\n",last);
        }
    }
    if(last==first) return 0;
    else return last-first;
*/