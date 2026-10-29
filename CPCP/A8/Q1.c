#include <stdio.h>

int main() {
    char s[100];
    int n = 0, i = 0;
    scanf("%s", s);
    while (s[i] != '\0') {
        n = n * 10 + (s[i] - '0');
        i++;
    }
    printf("%d\n", n);
    return 0;
}
