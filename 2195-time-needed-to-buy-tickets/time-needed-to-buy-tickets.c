int* push(int* arr,int size){
    int first = arr[0];
    //(first = 0) ? first = 0 : arr[0]-1;
    if(first==0)
        first = 0;
    else
        first = arr[0]-1;

    for(int i=0 ; i<size-1 ; i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = first;
    return arr;
}
int* pop(int* arr,int size){
    size = size-1;
    arr = realloc(arr,(size)*sizeof(int));
    return arr;
}
void watch(int* arr , int size){
    for(int i=0 ; i<size ; i++){
        printf("%d",arr[i]);
    }
}
int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int num = k;
    int target = tickets[k];
    int count = 0;
    int answer = 0;
    int check = 0;
    while(target!=0){
        if(num==0){
            num = ticketsSize;
            target--;
        }
        tickets = push(tickets,ticketsSize);
        if(tickets[ticketsSize-1]==0){
            tickets = pop(tickets,ticketsSize);
            ticketsSize = ticketsSize-1;
        }
        //watch(tickets,ticketsSize);
        //printf("\n");
        num--;
        count++;
        answer++;
        /*
        printf("num = %d\n",num);
        printf("target = %d\n",target);
        printf("count = %d\n",count);
        printf("answer = %d\n",answer);
        printf("ticketsSize = %d\n",ticketsSize);
        */
    }
    return answer;
}