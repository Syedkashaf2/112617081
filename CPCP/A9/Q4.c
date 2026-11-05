#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swap function: a = %d, b = %d\n", a, b);
}

int main() {
    int a = 10, b = 20;
    printf("Before swap in main: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("After swap in main: a = %d, b = %d\n", a, b);
    return 0;
}
