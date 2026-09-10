#include <stdio.h>

int main() {
    int n, temp, rev, rem;

    printf("Enter a 5-digit number: ");
    scanf("%d", &n);

    temp = n;
    rev = 0;

    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }

    printf("Reversed number = %d\n", rev);

    if (n == rev) {
        printf("Original and reversed numbers are equal\n");
    } else {
        printf("Original and reversed numbers are not equal\n");
    }

    return 0;
}
