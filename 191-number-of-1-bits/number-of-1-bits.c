int hammingWeight(int n) {
    int size = 0;
    int number = 0;
    int count = 0;
    int *array = NULL;
    while(1){
        array = (int*)realloc(array, (size + 1) * sizeof(int));
        array[number] = n%2;
        n = n/2;
        number++;
        size++;
        if(n==0)
            break;
    }
    //將array顛倒儲存在arr陣列中，arr為正確的二進制形式
    int arr[size]={};
    int record = 0;
    for(int i=size ; i>0 ; i--){
        arr[record] = array[i-1];
        printf("%d",arr[record]);
        record++;
    }
    //數二進制中有幾個1
    for(int i=0 ; i<size ; i++){
        if(array[i]==1)
            count++;
        else
            continue;        
    }
    return count;
}