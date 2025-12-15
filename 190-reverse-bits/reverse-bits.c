uint32_t reverseBits(uint32_t n) {
    uint32_t num = 0;
    for (int i=0 ; i<32 ; i++) {
        uint32_t bit = n & 1;
        n >>= 1;
        num <<= 1;
        num |= bit;
    }
    return num;
}