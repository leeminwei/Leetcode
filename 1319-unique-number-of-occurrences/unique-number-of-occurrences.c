bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2001] = {0};
    int number = arrSize;
    int* size = &number;
    //算出每個元素出現的頻率
    for(int i=0 ; i<*size ; i++){
        freq[arr[i]+1000]++;
    }
    //刪除陣列重複項
    for(int i=0 ; i<*size ; i++){
        for(int j=i+1 ; j<*size ;j++){
            if(arr[i] == arr[j]){
                for(int k=j ; k<*size-1 ; k++){
                    arr[k] = arr[k+1];
                }
                j--;
                (*size)--;
            }
        }
    }
    for(int i=0 ; i<*size ; i++){
        printf("%d的頻率 = %d\n",arr[i],freq[arr[i]+1000]);
    }
    for(int i=0 ; i<*size ; i++){
        for(int j=i+1 ; j<*size ; j++){
            if(freq[arr[i]+1000]==freq[arr[j]+1000])
                return false;
        }
    }  
    return true;
}