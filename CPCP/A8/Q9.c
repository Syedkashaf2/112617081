#include <stdio.h>

float prod(float a, int b)
{
    return a * b;
}

int main()
{
    float x, res;
    int y;
    scanf("%f %d", &x, &y);
    res = prod(x, y);
    printf("%f\n", res);
    return 0;
}
