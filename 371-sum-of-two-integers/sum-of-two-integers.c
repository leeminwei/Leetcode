int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = a & b; // 計算進位 (a 和 b 的相同位元都是 1)
        a = a ^ b;                  // 計算不帶進位的和 (a 和 b 的不同位元是 1)
        b = carry << 1;             // 將進位左移一位，準備加到下一位
    }
    return a;
}