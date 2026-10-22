#include <stdio.h>

int main() {
    char text[100];

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    printf("Entered string: ");
    fputs(text, stdout);

    return 0;
}
