#include <stdio.h>

int checkEvenOdd(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num = 10;
    if (checkEvenOdd(num) == 1) {
        printf("%d is Even\n", num);
    } else {
        printf("%d is Odd\n", num);
    }
    return 0;
}
