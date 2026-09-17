#include <stdio.h>

int main() {
    int n, i = 1;
    int fact = 1;
    scanf("%d", &n);
    while (i <= n) {
        fact = fact * i;
        i++;
    }
    printf("%d\n", fact);
    return 0;
}
