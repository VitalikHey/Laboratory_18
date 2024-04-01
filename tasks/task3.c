#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void rearrangeWord(char *word) {
    int len = 0;
    int numCount = 0, letterCount = 0;
    bool isNum = false;

    // Подсчитываем количество цифр и букв в слове
    while (word[len]) {
        if (isdigit(word[len])) {
            numCount++;
        } else if (isalpha(word[len])) {
            letterCount++;
        }
        len++;
    }

    char tmp[len];
    int i = 0, j = 0;

    // Переносим цифры в начало слова
    for (i = 0; i < len; i++) {
        if (isdigit(word[i])) {
            tmp[j++] = word[i];
        }
    }

    // Переносим буквы в конец слова
    for (i = 0; i < len; i++) {
        if (isalpha(word[i])) {
            tmp[j++] = word[i];
        }
    }

    tmp[j] = '\0';

    // Копируем измененное слово обратно в исходную строку
    for (i = 0; i < len; i++) {
        word[i] = tmp[i];
    }
}

void rearrangeString(char *s) {
    char *start = s;

    while (*s) {
        if (isalnum(*s)) {
            s++;
        } else {
            if (s > start) {
                rearrangeWord(start);
            }
            s++;
            start = s;
        }
    }

    if (s > start) {
        rearrangeWord(start);
    }
}

int main() {
    char sentence[] = "Th1s is a 2T3E5S7T s9en11tenc13e";

    printf("The original sentence %s\n", sentence);

    rearrangeString(sentence);

    printf("New sentence: %s\n", sentence);

    return 0;
}
