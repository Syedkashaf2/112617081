#include <stdio.h>

int main() {
    char source[] = "Copy Me!";
    char destination[50];
    int i = 0;

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
