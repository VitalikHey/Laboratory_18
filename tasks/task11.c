#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode printWordBeforeFirstWordWithA(char *s) {
    char *token, *prevToken;
    char *saveptr;
    int foundA = 0;
    prevToken = NULL;

    token = strtok_r(s, " ", &saveptr);

    while (token != NULL) {
        int i;
        for (i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);  // Переводим в нижний регистр
        }

        if (strstr(token, "a")) {
            foundA = 1;
            break;
        }

        prevToken = token;
        token = strtok_r(NULL, " ", &saveptr);
    }

    if (foundA) {
        if (prevToken != NULL) {
            printf("The word before the first word containing 'a': %s\n", prevToken);
            return WORD_FOUND;
        } else {
            printf("The first word contains 'a'.\n");
            return FIRST_WORD_WITH_A;
        }
    } else if (prevToken != NULL) {
        printf("There are no words with a letter in the line 'a'.\n");
        return NOT_FOUND_A_WORD_WITH_A;
    } else {
        printf("There are no words in the line.\n");
        return EMPTY_STRING;
    }
}

int main() {
    char str[] = "test example aardvark apple";
    printWordBeforeFirstWordWithA(str);

    return 0;
}
