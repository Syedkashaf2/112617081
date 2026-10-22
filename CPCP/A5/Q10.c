#include <stdio.h>

int main() {
    int a, b, temp;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    int x = a, y = b;
    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }

    printf("GCD of %d and %d is: %d\n", a, b, x);
    return 0;
}
