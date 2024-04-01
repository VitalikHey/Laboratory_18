#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#define MAX_STRING_SIZE 100

typedef struct {
    char *start;
    char *end;
} WordDescriptor;

void testRemoveExtraSpaces(char* input, char* expected_output) {
    char test_input[100];
    strcpy(test_input, input);
    removeExtraSpaces(test_input);

    if (strcmp(test_input, expected_output) != 0) {
        printf("Ошибка! Ввод: %s, Ожидалось: %s, Получено: %s\n", input, expected_output, test_input);
    } else {
        printf("Тест пройден успешно!\n");
    }
}

void testRearrangeString(char* input, char* expected_output) {
    char test_input[100];
    strcpy(test_input, input);
    rearrangeString(test_input);

    if (strcmp(test_input, expected_output) != 0) {
        printf("Ошибка! Ввод: %s, Ожидалось: %s, Получено: %s\n", input, expected_output, test_input);
    } else {
        printf("Тест пройден успешно!\n");
    }
}

void testReplaceDigitsWithSpaces(char* input, char* expected_output) {
    char test_output[MAX_STRING_SIZE];
    replaceDigitsWithSpaces(input, test_output);

    if (strcmp(test_output, expected_output) != 0) {
        printf("Ошибка! Ввод: %s, Ожидалось: %s, Получено: %s\n", input, expected_output, test_output);
    } else {
        printf("Тест пройден успешно!\n");
    }
}

void testReplace(char* input, char* w1, char* w2, char* expected_output) {
    char test_input[MAX_STRING_SIZE];
    strcpy(test_input, input);

    replace(test_input, w1, w2);

    if (strcmp(test_input, expected_output) != 0) {
        printf("Ошибка! Ввод: %s, Шаблон замены: %s, Замена: %s, Ожидалось: %s, Получено: %s\n", input, w1, w2, expected_output, test_input);
    } else {
        printf("Тест пройден успешно!\n");
    }
}

void testAreWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char word1[] = "apple";
    char word2[] = "banana";

    WordDescriptor desc1, desc2;
    desc1.start = word1;
    desc1.end = word1 + strlen(word1);
    desc2.start = word2;
    desc2.end = word2 + strlen(word2);

    // Проведем тесты, ожидающие неравенство слов
    if (areWordsEqual(desc1, desc2) == 0) {
        printf("Тест пройден успешно для неравных слов.\n");
    } else {
        printf("Ошибка! Ожидалось неравенство слов.\n");
    }

    // Проведем тесты, ожидающие равенство слов
    if (areWordsEqual(desc1, desc1) == 1) {
        printf("Тест пройден успешно для равных слов.\n");
    } else {
        printf("Ошибка! Ожидалось равенство слов при сравнении одного слова.\n");
    }

}

void testBagOfWords(char *input) {
    BagOfWords bag;
    getBagOfWords(&bag, input);

    fprintf(stderr, "Words in bag:\n");
    for (size_t i = 0; i < bag.size; i++) {
        fprintf(stderr, "Word %lu: %.*s\n", i + 1, (int)(bag.words[i].end - bag.words[i].start), bag.words[i].start);
    }
}

