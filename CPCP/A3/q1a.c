#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);
    (ch >= 'a' && ch <= 'z') ? printf("Lowercase alphabet\n") : printf("Not a lowercase alphabet\n");
    return 0;
}
