//用bitmask來代表words[i]的結果
int bitmask(char* s) {
    int size = strlen(s);
    int arr = 0;
    for (int i = 0; i < size; i++) {
        arr |= 1 << (s[i] - 'a');
    }
    return arr;
}

int similarPairs(char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (bitmask(words[i]) == bitmask(words[j])) {
                count++;
            }
        }
    }
    return count;
}