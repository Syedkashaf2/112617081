#include <stdio.h>

int main() {
    float sum = 0.0;
    float fact = 1.0;

    for (int i = 1; i <= 7; i++) {
        fact = fact * i;
        sum = sum + (i / fact);
    }

    printf("Sum of first seven terms: %f\n", sum);

    return 0;
}
