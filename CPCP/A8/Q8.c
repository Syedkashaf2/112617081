#include <stdio.h>

long long power(int a, int b) {
    long long p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", power(a, b));
    return 0;
}
