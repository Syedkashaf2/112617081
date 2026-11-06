#include <stdio.h>

int isArmstrong(int num)
{
    int temp = num;
    int sum = 0;
    int digit;
    while (temp > 0)
    {
        digit = temp % 10;
        sum = sum + (digit * digit * digit);
        temp = temp / 10;
    }
    if (sum == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num = 153;
    if (isArmstrong(num) == 1)
    {
        printf("%d is an Armstrong number\n", num);
    }
    else
    {
        printf("%d is not an Armstrong number\n", num);
    }
    return 0;
}
