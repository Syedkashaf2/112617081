#include <stdio.h>

int findCube(int num)
{
    return num * num * num;
}

int main()
{
    int num = 5;
    int result = findCube(num);
    printf("Cube of %d is %d\n", num, result);
    return 0;
}
