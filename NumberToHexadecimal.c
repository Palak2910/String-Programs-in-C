char* toHex(int num) {
    if(num == 0) {
        char* result = (char*)malloc(2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char* result = (char*)malloc(9);
    char hex[] = "0123456789abcdef";
    int i = 0;

    unsigned int n = (unsigned int)num;

    while (n != 0) {
        result[i++] = hex[n & 15];
        n >>= 4;
    }
    result[i] = '\0';

    for(int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = result[j];
        result[j] = result[k];
        result[k] = temp;
    }
    return result;
}
