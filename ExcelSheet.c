char* convertToTitle(int columnNumber) {
    char* result = (char*)malloc(20 * sizeof(char));
    int i = 0;

    while (columnNumber > 0) {
        columnNumber--;

        result[i] = 'A' + (columnNumber % 26);
        i++;

        columnNumber /= 26;
    }

    result[i] = '\0';

    int left = 0;
    int right = i - 1;

    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;

        left++;
        right--;

    }
    return result;
}
