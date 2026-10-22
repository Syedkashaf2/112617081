#include <stdio.h>

int main() {
    int num, originalNum, rev = 0, rem;
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;
    while (num > 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    if (originalNum == rev)
        printf("%d is a Palindrome\n", originalNum);
    else
        printf("%d is not a Palindrome\n", originalNum);

    return 0;
}
