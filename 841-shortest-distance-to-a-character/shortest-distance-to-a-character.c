/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    int size = strlen(s);
    int* arr = malloc(size*sizeof(int));
    int number = 0;
    for(int i=0 ; i<size ; i++){
        if(s[i]==c){
            arr[number++] = i;
        }
    }
    arr = realloc(arr,number*sizeof(int));
    int len = 0;
    int *answer = malloc(size*sizeof(int));
    int index = 0;
    for(int i=0 ; i<size ; i++){
        int min = size;
        for(int j=0 ; j<number ; j++){
            len = abs(i-arr[j]);
            if(len<min)
                min = len;
        }
        answer[index++] = min;
    }
    *returnSize = index;
    return answer;
}