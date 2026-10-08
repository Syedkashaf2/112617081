#include <stdio.h>
int main()
{
    int a[100], n, i, x, count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        if (a[i] > x)
            count++;
    }
    printf("Count = %d", count);
    return 0;
}
