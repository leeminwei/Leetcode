char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int number = 0;
    char *arr = (char*)calloc((lettersSize),sizeof(char));
    for(int i=0 ; i<lettersSize ; i++){
        if(letters[i]>target){
            arr[number] = letters[i];
            number++;
        }
    }

    int a;
    if(number > 0){
        for(int i=0 ; i<number ; i++){
            for(int j=i+1 ; j<number ; j++){
                if(arr[i]>arr[j]){
                    a = arr[i];
                    arr[i]=arr[j];
                    arr[j]=a;
                }
            }
        }
        return arr[0];
    }
    return letters[0];
}
