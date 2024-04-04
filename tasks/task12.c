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

void wordDescriptorToString(WordDescriptor word, char *destination) {
    strcpy(destination, word.word);
}

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

WordDescriptor lastWordInFirstStringInSecondString(char *str1, char *str2) {
    BagOfWords bag1 = createBagOfWords(str1);
    BagOfWords bag2 = createBagOfWords(str2);

    for (int i = bag1.size - 1; i >= 0; i--) {
        for (int j = 0; j < bag2.size; j++) {
            if (strcmp(bag1.words[i].word, bag2.words[j].word) == 0) {
                return bag1.words[i];
            }
        }
    }

    WordDescriptor empty;
    strcpy(empty.word, "");
    empty.count = 0;
    return empty;
}

int main() {
    char str1[] = "hello world foo bar";
    char str2[] = "baz bar qux world";

    WordDescriptor word = lastWordInFirstStringInSecondString(str1, str2);

    char string[MAX_WORD_LENGTH];
    wordDescriptorToString(word, string);

    printf("Last word in first string found in the second string: %s\n", string);

    return 0;
}

