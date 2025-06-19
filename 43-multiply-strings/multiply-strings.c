#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* reverse(char* s, int len) {
    char* answer = (char*)malloc((len+1)*sizeof(char));
    int idx = 0;
    for (int i=len-1 ; i>=0 ; i--) {
        answer[idx++] = s[i];
    }
    answer[idx] = '\0';
    free(s);
    return answer;
}

char* multiply(char* num1, char* num2) {
    if (strcmp(num1,"0")==0 || strcmp(num2,"0")==0) {
        return "0";
    } 
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int sum = 0;
    int n = len1 + len2;
    int* arr = (int*)calloc((len1+len2), sizeof(int));
    for (int i=len1-1 ; i>=0 ; i--) {
        for (int j=len2-1 ; j>=0 ; j--) {
            int digit1 = num1[i]-'0';
            int digit2 = num2[j]-'0';
            int pos1 = i+j+1;  //放sum的個位數
            int pos2 = i+j;    //放sum的十位數
            sum = digit1 * digit2 + arr[pos1] + arr[pos2]*10;
            arr[pos1] = sum%10;
            arr[pos2] = sum/10;
        }
    }
   
    //index為找到第一個不為0的位置
    int index = 0;
    while(arr[index] == 0) {
        index++;
    }
    printf("index = %d\n", index);
    int result_len = n - index;
    char* result = (char*)malloc(result_len + 1);  // +1 for '\0'
    
    //從第一個不為0的值開始
    for (int i = 0; i < result_len; i++) {
        result[i] = arr[index + i] + '0';
    }
    result[result_len] = '\0';

    free(arr);
    return result;
}