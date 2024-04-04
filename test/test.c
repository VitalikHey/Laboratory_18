#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <assert.h>

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

void testAlternateStrings() {
    char str1[] = "Hello World";
    char str2[] = "Good Morning";
    char result[100];

    alternateStrings(str1, str2, result);

    char expected[] = "Hello Good World Morning";

    assert(strcmp(result, expected) == 0);
}

void testPrintWordBeforeFirstWordWithA() {
    char input1[] = "Alpha Beta Gamma";
    char input2[] = "Bravo Charlie Delta";
    char input3[] = "Echo";

    assert(printWordBeforeFirstWordWithA(input1) == FIRST_WORD_WITH_A);
    assert(printWordBeforeFirstWordWithA(input2) == WORD_FOUND);
    assert(printWordBeforeFirstWordWithA(input3) == NOT_FOUND_A_WORD_WITH_A);
}

void testLastWordInFirstStringInSecondString() {
    // Подготавливаем тестовые данные для функции

    char str1[] = "apple banana apple";
    char str2[] = "orange banana";

    // Вызываем функцию и сохраняем результат в переменной
    WordDescriptor result = lastWordInFirstStringInSecondString(str1, str2);

    // Ожидаем, что последнее слово будет "banana"
    assert(strcmp(result.word, "banana") == 0);
    assert(result.count > 0);
}

void testHasDuplicateWords() {
    char str1[] = "Apple Banana Cherry Apple";
    char str2[] = "Orange Mango Mango";

    assert(hasDuplicateWords(str1) == 1); // Ожидаем наличие дублирующихся слов
    assert(hasDuplicateWords(str2) == 1); // Ожидаем наличие дублирующихся слов
}

void testHasSameSetOfLetters() {
    char str1[] = "apple elppa banana ananab";
    char str2[] = "hello world";

    assert(hasSameSetOfLetters(str1) == 1); // Ожидаем наличие пары слов с одинаковым набором букв
    assert(hasSameSetOfLetters(str2) == 0); // Ожидаем отсутствие пары слов с одинаковым набором букв
}

void testGetWordsDifferentFromLast() {
    char str1[] = "apple banana cherry apple";
    char expected1[] = "banana cherry ";
    char *result1 = getWordsDifferentFromLast(str1);
    assert(strcmp(result1, expected1) == 0);

    char str2[] = "hello world hello";
    char expected2[] = "world ";
    char *result2 = getWordsDifferentFromLast(str2);
    assert(strcmp(result2, expected2) == 0);

    free(result1);
    free(result2);
}

void testFindWordBefore() {
    char s1[] = "apple banana cherry";
    char s2[] = "banana";
    char* expected1 = "apple";
    char* result1 = findWordBefore(s1, s2);
    assert(strcmp(result1, expected1) == 0);

    char s3[] = "hello world";
    char s4[] = "world";
    char* expected2 = "hello";
    char* result2 = findWordBefore(s3, s4);
    assert(strcmp(result2, expected2) == 0);

    assert(findWordBefore("one two three", "four") == NULL);
}

void testRemoveWordsWithRepeatedChars() {
    char input1[] = "apple banana cherry pears";
    char expected1[] = "apple pears ";
    removeWordsWithRepeatedChars(input1);
    assert(strcmp(input1, expected1) == 0);

    char input2[] = "hello apple orange";
    char expected2[] = "hello orange ";
    removeWordsWithRepeatedChars(input2);
    assert(strcmp(input2, expected2) == 0);

    char input3[] = "test string";
    char expected3[] = "test string ";
    removeWordsWithRepeatedChars(input3);
    assert(strcmp(input3, expected3) == 0);
}

void testStringConcatenation() {
    char str1[] = "Hello world";
    char str2[] = "this is a test";

    char expected1[] = "Hello world test";
    char lastWord = strrchr(str2, ' ') + 1;

    if (countWordsInString(str1) < countWordsInString(str2)) {
        appendStringToFirstString(str1, lastWord);
        assert(strcmp(str1, expected1) == 0);
    } else {
        appendStringToFirstString(str2, lastWord);
        assert(strcmp(str2, expected1) == 0);
    }
}

void testCheckWordInString() {
    // Тестирование на обычных данных
    assert(checkWordInString("apple", "plape") == 1); // Ожидается успешное нахождение всех букв слова "apple" в строке "plape"
    assert(checkWordInString("hello", "hheelllloo") == 1); // Ожидается успешное нахождение всех букв слова "hello" в строке "hheelllloo"

    // Тестирование на неверных данных
    assert(checkWordInString("world", "word") == 0); // Ожидается неудачное нахождение всех букв слова "world" в строке "word"
    assert(checkWordInString("python", "py") == 0); // Ожидается неудачное нахождение всех букв слова "python" в строке "py"
}
