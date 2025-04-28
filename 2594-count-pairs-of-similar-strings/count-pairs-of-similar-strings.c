int bitmask(char* s) {
    int size = strlen(s);
    int arr = 0; // 不是指標，只是一個整數
    for (int i = 0; i < size; i++) {
        arr |= 1 << (s[i] - 'a');
    }
    return arr;
}

int similarPairs(char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) { // 要兩層迴圈
            if (bitmask(words[i]) == bitmask(words[j])) {
                count++;
            }
        }
    }
    return count;
}