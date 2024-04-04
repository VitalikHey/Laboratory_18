#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordDescriptor;

typedef struct {
    WordDescriptor words[MAX_WORDS];
    int size;
} BagOfWords;

BagOfWords createBagOfWords(char *str) {
    BagOfWords bag;
    char *token, *saveptr;
    bag.size = 0;

    token = strtok_r(str, " ", &saveptr);

    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < bag.size; i++) {
            if (strcmp(bag.words[i].word, token) == 0) {
                bag.words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            WordDescriptor newWord;
            strcpy(newWord.word, token);
            newWord.count = 1;
            bag.words[bag.size++] = newWord;
        }

        token = strtok_r(NULL, " ", &saveptr);
    }

    return bag;
}

int hasDuplicateWords(char *str) {
    BagOfWords bag = createBagOfWords(str);

    for (int i = 0; i < bag.size; i++) {
        if (bag.words[i].count > 1) {
            return 1; // Есть одинаковые слова
        }
    }

    return 0; // Нет одинаковых слов
}

int main() {
    char str[] = "hello world foo bar world";

    if (hasDuplicateWords(str)) {
        printf("String is have equal words\n");
    } else {
        printf("String isn't have equal words\n");
    }

    return 0;
}
