#include <stdio.h>

int main() {
    char str[] = "This is a test string";
    int count = 0, inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!inWord) {
                inWord = 1;
                count++;
            }
        } else {
            inWord = 0;
        }
    }

    printf("The string is: \"%s\"\n", str);
    printf("Total number of words: %d\n", count);

    return 0;
}
