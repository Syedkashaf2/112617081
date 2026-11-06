#include <stdio.h>

void calc(float m1, float m2, float m3, float *avg, float *per)
{
    *avg = (m1 + m2 + m3) / 3.0;
    *per = ((m1 + m2 + m3) / 300.0) * 100.0;
}

int main()
{
    float m1, m2, m3, avg, per;
    scanf("%f %f %f", &m1, &m2, &m3);
    calc(m1, m2, m3, &avg, &per);
    printf("Average: %.2f\n", avg);
    printf("Percentage: %.2f\n", per);
    return 0;
}
