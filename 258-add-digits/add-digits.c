int addDigits(int num) {
     int digit;
     while (num > 0) {
        digit = num % 10; 
        printf("digit = %d\n", digit); 
        num = num / 10;
        printf("num = %d\n",num);
        num+=digit;
        if (num < 10)
          break;   
    }    
     return num;
}