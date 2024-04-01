#include <stdio.h>
#include <string.h>

typedef struct {
    char *start;
    char *end;
} WordDescriptor;

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    int len1 = w1.end - w1.start;
    int len2 = w2.end - w2.start;

    if (len1 != len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (w1.start[i] != w2.start[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char sentence[] = "apple banana cherry";

    WordDescriptor words[3];

    char *token = strtok(sentence, " ");
    int wordCount = 0;
    while (token != NULL) {
        words[wordCount].start = token;
        words[wordCount].end = token + strlen(token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    int ordered = 1;

    for (int i = 0; i < wordCount - 1; i++) {
        if (!areWordsEqual(words[i], words[i+1]) && strncmp(words[i].start, words[i+1].start, words[i].end - words[i].start) > 0) {
            ordered = 0;
            break;
        }
    }

    if (ordered) {
        printf("All is good\n");
    } else {
        printf("All is bad\n");
    }

    return 0;
}
