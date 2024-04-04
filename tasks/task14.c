#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100

char* sortWord(char *word) {
    int length = strlen(word);
    char *sortedWord = (char*)malloc((length + 1) * sizeof(char));
    strcpy(sortedWord, word);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (tolower(sortedWord[j]) > tolower(sortedWord[j + 1])) {
                char temp = sortedWord[j];
                sortedWord[j] = sortedWord[j + 1];
                sortedWord[j + 1] = temp;
            }
        }
    }

    return sortedWord;
}

int hasSameSetOfLetters(char *str) {
    char *buffer = strdup(str);
    char *token, *saveptr;
    char *words[MAX_WORDS];
    int numWords = 0;

    token = strtok_r(buffer, " ", &saveptr);

    while (token != NULL) {
        words[numWords++] = strdup(token);
        token = strtok_r(NULL, " ", &saveptr);
    }

    for (int i = 0; i < numWords; i++) {
        char *sortedWord1 = sortWord(words[i]);
        for (int j = i + 1; j < numWords; j++) {
            char *sortedWord2 = sortWord(words[j]);
            if (strcmp(sortedWord1, sortedWord2) == 0) {
                free(sortedWord1);
                free(sortedWord2);
                return 1; // Есть пара слов с одинаковым набором букв
            }
            free(sortedWord2);
        }
        free(sortedWord1);
    }

    return 0; // Нет пары слов с одинаковым набором букв
}

int main() {
    char str[] = "hello world foo bar dlrow";

    if (hasSameSetOfLetters(str)) {
        printf("There are a couple of words with the same set of letters in the string\n");
    } else {
        printf("There are no pairs of words with the same set of letters in the string\n");
    }

    return 0;
}
