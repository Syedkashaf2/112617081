#include <stdio.h>

int main() {
    int num;
    int pos = 0;
    int neg = 0;
    int zero = 0;
    char ch;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num > 0) {
            pos++;
        } else if (num < 0) {
            neg++;
        } else {
            zero++;
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("Positive count: %d\n", pos);
    printf("Negative count: %d\n", neg);
    printf("Zero count: %d\n", zero);

    return 0;
}
