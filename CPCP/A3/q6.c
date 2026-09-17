#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a = 0, b = 1;
    while (a <= n) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}
