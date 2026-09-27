#include <stdio.h>

int main() {
    int i;
    int j;
    int isPrime;

    for (i = 1; i <= 300; i++) {
        if (i <= 1) {
            continue;
        }

        isPrime = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
