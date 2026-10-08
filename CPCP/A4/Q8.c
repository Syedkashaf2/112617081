#include <stdio.h>
int main()
{
    int i, j;
    for (i = 1; i <= 24; i++)
    {
        for (j = 1; j <= 80; j++)
        {
            if ((i + j) % 2 == 0)
                printf("%c", 3);
            else
                printf("%c", 4);
        }
    }
    return 0;
}
