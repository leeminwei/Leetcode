#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int countone(int n) {
    int count = 0;
    while (n>0) {
        n&=(n-1);
        count++;
    }
    return count;
}

int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    for (int bit=0 ; bit<32 ; bit++) {
        int zero = 0;
        int one = 0;
        for (int j=0 ; j<numsSize ; j++) {
            //判斷這個bit是否為1
            if ((nums[j] >> bit) & 1 == 1) {
                one++;
            }
            else {
                zero++;
            }
        }
        sum += (one * zero);
        
    }
    return sum;
}