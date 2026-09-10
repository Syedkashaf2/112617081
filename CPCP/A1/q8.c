#include <stdio.h>

int main() {
    int num, d1, d2, d3, d4, d5, reversed_num;

    printf("Enter a 5-digit number: ");
    scanf("%d", &num);

    d5 = num % 10;          
    d4 = (num / 10) % 10;   
    d3 = (num / 100) % 10; 
    d2 = (num / 1000) % 10;
    d1 = num / 10000;       

    reversed_num = (d5 * 10000) + (d4 * 1000) + (d3 * 100) + (d2 * 10) + d1;


    printf("Reversed number: %05d\n", reversed_num);

    return 0;
}

