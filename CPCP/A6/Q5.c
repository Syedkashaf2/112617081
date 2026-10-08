#include <stdio.h>
int main()
{
    int a[100], n, i, large, slarge;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    large = a[0];
    slarge = a[0];
    for (i = 0; i < n; i++)
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
    printf("Second largest = %d\n", slarge);
    return 0;
}
