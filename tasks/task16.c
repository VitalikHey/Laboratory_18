#include <stdio.h>
#include <string.h>

char* findWordBefore(char *s1, char *s2) {
    char* word = strtok(s1, " ");
    char* prevWord = "";

    while (word != NULL) {
        if (strstr(s2, word)) {
            return prevWord;
        }
        prevWord = word;
        word = strtok(NULL, " ");
    }

    return NULL;
}

int main() {
    char s1[] = "Two lines s1 and s2 are given. Let w be the first of the words of string s1, which is also in string s2.";
    char s2[] = "which s1 is a string in Let and s2";

    char* result = findWordBefore(s1, s2);
    if (result != NULL) {
        printf("The word preceding the first occurrence w in s1: %s\n", result);
    } else {
        printf("Word is not found\n");
    }

    return 0;
}

