#include <stdio.h>
#include "tasks.h"


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
