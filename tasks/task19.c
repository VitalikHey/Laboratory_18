#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkWordInString(char *word, char *str) {
    int charFlags[26] = {0}; // массив флагов для каждой буквы алфавита

    // приводим все буквы в слове к нижнему регистру
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    // отмечаем найденные буквы в массиве флагов
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {
            charFlags[c - 'a'] = 1;
        }
    }

    // проверяем, были ли найдены все буквы из слова
    for (int i = 0; word[i] != '\0'; i++) {
        if (!charFlags[word[i] - 'a']) {
            return 0; // не все буквы найдены
        }
    }

    return 1; // все буквы найдены
}

int main() {
    char word[] = "hello";
    char str[] = "helloworld";
    if (checkWordInString(word, str)) {
        printf("Every letter of the word is present in the string\n");
    } else {
        printf("Not every letter of the word is present in the string\n");
    }
    return 0;
}
