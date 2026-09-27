#include <stdio.h>

int main() {
  
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7 - i; j++) {
            printf("%c", 'A' + j);
        }

        for (int j = 0; j < 2 * i - 1; j++) {
            printf(" ");
        }

        for (int j = 6 - i; j >= 0; j--) {
            if (i == 0 && j == 6) {
                continue;
            }
            printf("%c", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}
