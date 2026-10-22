#include <stdio.h>

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    printf("Odd numbers from 1 to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
