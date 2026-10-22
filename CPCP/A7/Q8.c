#include <stdio.h>

int main() {
    char str1[] = "apple";
    char str2[] = "apple";
    int i = 0, areSame = 1;

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            areSame = 0;
            break;
        }
        i++;
    }

    if (areSame)
        printf("The strings are identical.\n");
    else
        printf("The strings are not identical.\n");

    return 0;
}
