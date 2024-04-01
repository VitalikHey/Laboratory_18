#include <stdio.h>
#include <ctype.h>
#include "tasks.h"

#define MAX_STRING_SIZE 100

void removeExtraSpaces(char *s) {
    int i, j;
    int space = 0;
    for (i = 0, j = 0; s[i]; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];
            space = 0;
        } else {
            if (!space && j > 0) {
                s[j++] = ' ';
                space = 1;
            }
        }
    }
    s[j] = '\0';

    // Удаление пробела в начале строки
    if (j > 0 && s[0] == ' ') {
        // Сдвигаем все символы влево на одну позицию
        for (i = 0; s[i]; i++) {
            s[i] = s[i + 1];
        }
    }
}

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