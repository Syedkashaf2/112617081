#include <stdio.h>

int main() {
    int num;
    int temp;
    int rem;
    int oct = 0;
    int place = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    while (temp > 0) {
        rem = temp % 8;
        oct = oct + rem * place;
        place = place * 10;
        temp = temp / 8;
    }

    printf("Octal equivalent: %d\n", oct);

    return 0;

}