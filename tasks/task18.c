#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int count1 = 0, count2 = 0;

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == ' ') {
            count1++;
        }
    }
    count1++;

    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == ' ') {
            count2++;
        }
    }
    count2++; // Adding 1 to count2 to include the last word

    if (count1 < count2) {
        printf("The first string has fewer words. Appending the last word from the second string.\n");
        char* lastWord = strrchr(str2, ' ') + 1;
        strcat(str1, " ");
        strcat(str1, lastWord);
        printf("The updated string is: %s\n", str1);
    } else {
        printf("The second string has fewer words. Appending the last word from the first string.\n");
        char* lastWord = strrchr(str1, ' ') + 1;
        strcat(str2, " ");
        strcat(str2, lastWord);
        printf("The updated string is: %s\n", str2);
    }

    return 0;
}

