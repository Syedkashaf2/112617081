#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0, i = 1;
    while (i <= n) {
        if (n % i == 0) {
            count++;
        }
        i++;
    }
    if (count == 2) {
        printf("%d is Prime\n", n);
    } else {
        printf("%d is Not Prime\n", n);
    }

    printf("Primes between 1 and %d: ", n);
    int num = 2;
    while (num <= n) {
        int factors = 0, j = 1;
        while (j <= num) {
            if (num % j == 0) {
                factors++;
            }
            j++;
        }
        if (factors == 2) {
            printf("%d ", num);
        }
        num++;
    }
    printf("\n");
    return 0;
}
