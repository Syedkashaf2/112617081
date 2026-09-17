#include <stdio.h>

int main() {
    int num = 100;
    while (num <= 500) {
        int temp = num;
        int sum = 0;
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit * digit;
            temp /= 10;
        }
        if (sum == num) {
            printf("%d\n", num);
        }
        num++;
    }
    return 0;
}
