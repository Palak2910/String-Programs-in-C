bool wordPattern(char* pattern, char* s) {
    char *words[300];
    int wordCount = 0;

    char *token = strtok(s," ");

    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }
    if (wordCount != strlen(pattern))
    return false;

    char *map[26] = {NULL};

    for (int i = 0; i < wordCount; i++) {
        int index = pattern[i] - 'a';

        if (map[index] != NULL) {
            if (strcmp(map[index], words[i]) != 0)
            return false;
        }
        else{
            for (int j = 0; j <26; j++) {
                if (map[j] !=NULL && strcmp(map[j], words[i]) == 0)
                return false;
            }
            map[index] = words[i];
        }
    }
    return true;
}
