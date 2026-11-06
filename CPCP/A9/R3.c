#include <stdio.h>

int sumOfDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return (num % 10) + sumOfDigits(num / 10);
}

int main()
{
    int num = 1234;
    int result = sumOfDigits(num);
    printf("Sum of digits of %d is %d\n", num, result);
    return 0;
}
