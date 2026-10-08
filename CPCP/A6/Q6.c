#include <stdio.h>
int main()
{
    int a[100], n, i, large, slarge;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (a[0] > a[1])
    {
        large = a[0];
        slarge = a[1];
    }
    else
    {
        large = a[1];
        slarge = a[0];
    }
    for (i = 2; i < n; i++)
    {
        if (a[i] > large)
        {
            slarge = large;
            large = a[i];
        }
        else if (a[i] > slarge)
        {
            slarge = a[i];
        }
    }
    printf("Second largest = %d", slarge);
    return 0;
}
