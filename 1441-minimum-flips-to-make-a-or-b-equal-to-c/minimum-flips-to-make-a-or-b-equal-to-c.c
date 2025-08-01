int minFlips(int a, int b, int c){
    unsigned int max = 1U << 31;
    int count = 0;
    unsigned int ua = (unsigned int)a;
    unsigned int ub = (unsigned int)b;
    unsigned int uc = (unsigned int)c;
    for (int i=0 ; i<32 ; i++) {
        int status = 0;
        int a_bit = (ua & max) ? 1 : 0;
        int b_bit = (ub & max) ? 1 : 0;
        int c_bit = (uc & max) ? 1 : 0;
        if ((a_bit | b_bit) != c_bit && c_bit == 1) {
            count++;
        }
        else if ((a_bit | b_bit) != c_bit && c_bit == 0) {
            if (a_bit == 1) {
                count++;
            }
            if (b_bit == 1) {
                count++;
            }
        }
        ua <<= 1;
        ub <<= 1;
        uc <<= 1;
    }
    return count;
}