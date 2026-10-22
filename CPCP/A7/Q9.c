#include <stdio.h>

int main() {
    char str[] = "c Programming Is Fun 123";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }

    printf("Uppercase string: %s\n", str);

    return 0;
}
