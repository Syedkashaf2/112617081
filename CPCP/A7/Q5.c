#include <stdio.h>

int main() {
    char str[] = "Hello World!";
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    printf("The string is: \"%s\"\n", str);
    printf("The length of the string is: %d\n", length);

    return 0;
}
