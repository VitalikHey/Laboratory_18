#include <stdio.h>
#include <string.h>

#define MAX_N_WORDS_IN_STRING 100

typedef struct {
    char *start;
    char *end;
} WordDescriptor;

typedef struct {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

void getBagOfWords(BagOfWords *bag, char *s) {
    char *token = strtok(s, " ");
    size_t wordCount = 0;

    while (token != NULL) {
        size_t wordLen = strlen(token);

        bag->words[wordCount].start = token;
        bag->words[wordCount].end = token + wordLen;

        wordCount++;
        token = strtok(NULL, " ");
    }

    bag->size = wordCount;
}

int main() {
    char sentence[] = "Hello World, this is a test";
    BagOfWords bag;
    getBagOfWords(&bag, sentence);

    for (int i = bag.size - 1; i >= 0; i--) {
        for (char *ptr = bag.words[i].start; ptr < bag.words[i].end; ptr++) {
            printf("%c", *ptr);
        }
        printf("\n");
    }

    return 0;
}

