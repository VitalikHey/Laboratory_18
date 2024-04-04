#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool hasRepeatedChars(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len - 1; i++) {
        if (strchr(word + i + 1, word[i]) != NULL) {
            return true;
        }
    }
    return false;
}

void removeWordsWithRepeatedChars(char *input) {
    char *word = strtok(input, " ");
    char result[1000] = "";

    while (word != NULL) {
        if (!hasRepeatedChars(word)) {
            strcat(result, word);
            strcat(result, " ");
        }
        word = strtok(NULL, " ");
    }

    strcpy(input, result);
}

int main() {
    char string[] = "Delete words containing duplicate characters from this line";
    removeWordsWithRepeatedChars(string);
    printf("Result: %s\n", string);
    return 0;
}

