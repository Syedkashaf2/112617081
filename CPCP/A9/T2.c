#include <stdio.h>

int globalVar = 10;

void testVariables()
{
    auto int autoVar = 10;
    static int staticVar = 10;
    register int regVar = 10;

    autoVar++;
    staticVar++;
    regVar++;
    globalVar++;

    printf("auto = %d, static = %d, register = %d, global = %d\n", autoVar, staticVar, regVar, globalVar);
}

int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        testVariables();
    }
    return 0;
}
