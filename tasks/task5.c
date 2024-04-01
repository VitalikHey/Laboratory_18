#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);

    char result[MAX_STRING_SIZE];
    char *resPtr = result;
    char *srcPtr = source;
    while (*srcPtr) {
        if (strncmp(srcPtr, w1, w1Size) == 0 && (srcPtr == source || !isalnum(*(srcPtr - 1))) &&
            (*(srcPtr + w1Size) == '\0' || !isalnum(*(srcPtr + w1Size)))) {
            for (size_t i = 0; i < w2Size; i++) {
                *resPtr = w2[i];
                resPtr++;
            }
            srcPtr += w1Size;
        } else {
            *resPtr = *srcPtr;
            resPtr++;
            srcPtr++;
        }
    }
    *resPtr = '\0';

    strcpy(source, result);
}

int main() {
    char source[MAX_STRING_SIZE] = "This is an example with word1 and word1 again.";

    char w1[] = "word1";
    char w2[] = "word2";

    replace(source, w1, w2);

    printf("Original string %s\n", source);

    return 0;
}
