#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100

void replaceDigitsWithSpaces(char *input, char *output) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            int numSpaces = input[i] - '0'; // Получаем количество пробелов из цифры
            for (int k = 0; k < numSpaces && j < MAX_STRING_SIZE-1; k++) {
                output[j++] = ' '; // Заменяем цифру соответствующим числом пробелов
            }
        } else if (j < MAX_STRING_SIZE-1) {
            output[j++] = input[i]; // Копируем символ, если это не цифра
        }
        i++;
    }

    output[j] = '\0'; // Добавляем завершающий нулевой символ
}

int main() {
    char originalString[MAX_STRING_SIZE] = "H3ll0 W0rld!";

    char buffer[MAX_STRING_SIZE];
    char resultString[MAX_STRING_SIZE];

    strncpy(buffer, originalString, MAX_STRING_SIZE);

    replaceDigitsWithSpaces(buffer, resultString);

    printf("first string: %s\n", originalString);
    printf("second string: %s\n", resultString);

    return 0;
}
