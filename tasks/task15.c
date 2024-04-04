#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getWordsDifferentFromLast(char *str) {
    char *buffer = strdup(str);
    char *token, *saveptr;
    char *lastWord;
    char *result = (char*)malloc(strlen(str) * sizeof(char));
    result[0] = '\0';

    token = strtok_r(buffer, " ", &saveptr);

    while (token != NULL) {
        lastWord = token;
        token = strtok_r(NULL, " ", &saveptr);
    }

    buffer = strdup(str);
    token = strtok(buffer, " ");
    while (token != NULL) {
        if (strcmp(token, lastWord) != 0) {
            strcat(result, token);
            strcat(result, " ");
        }
        token = strtok(NULL, " ");
    }

    return result;
}

int main() {
    char str[] = "hello world foo bar world";

    char *diffWords = getWordsDifferentFromLast(str);
    printf("Words other than the last word: %s\n", diffWords);

    free(diffWords);

    return 0;
}
