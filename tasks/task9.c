#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void alternateStrings(char *str1, char *str2, char *result) {
    char *token1, *token2;
    char *saveptr1, *saveptr2;

    token1 = strtok_r(str1, " ", &saveptr1);
    token2 = strtok_r(str2, " ", &saveptr2);

    while (token1 != NULL || token2 != NULL) {
        if (token1 != NULL) {
            strcpy(result, token1);
            result += strlen(token1);
            *result = ' ';
            result++;
            token1 = strtok_r(NULL, " ", &saveptr1);
        }

        if (token2 != NULL) {
            strcpy(result, token2);
            result += strlen(token2);
            *result = ' ';
            result++;
            token2 = strtok_r(NULL, " ", &saveptr2);
        }
    }

    *(result - 1) = '\0';  // Убираем последний пробел
}

int main() {
    char str1[] = "apple banana cherry";
    char str2[] = "dog cat";
    char result[MAX_LENGTH];

    alternateStrings(str1, str2, result);

    printf("Result: %s\n", result);

    return 0;
}
