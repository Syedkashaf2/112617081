#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);
    ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) 
        ? printf("Not a special symbol\n") 
        : printf("Special symbol\n");
    return 0;
}
