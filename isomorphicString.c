bool isIsomorphic(char* s, char* t) {
    int mapST[256] = {0};
    int mapTS[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char a = s[i];
        unsigned char b = t[i];

        if (mapST[a] != 0 && mapST[a] != b+1) {
            return false;
        }

        if (mapTS[b] != 0 && mapTS[b] != a+1) {
            return false;
        }
        mapST[a] = b+1;
        mapTS[b] = a+1;
    }
    return true;
}
