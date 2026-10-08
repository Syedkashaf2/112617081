#include <stdio.h>
int main()
{
    int a[100], n, i, large, small, even = 0, odd = 0;
    float sum = 0, avg;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    large = a[0];
    small = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > large)
            large = a[i];
        if (a[i] < small)
            small = a[i];
        sum = sum + a[i];
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    avg = sum / n;
    printf("Largest = %d\n", large);
    printf("Smallest = %d\n", small);
    printf("Average = %f\n", avg);
    printf("Even = %d\nOdd = %d", even, odd);
    return 0;
}
