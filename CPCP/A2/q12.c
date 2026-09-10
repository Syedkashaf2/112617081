#include <stdio.h>
#include <math.h>

int main() {
	float x, y, r, x1, y1, d;

	printf("Enter center coordinates (x, y) and radius: ");
	scanf("%f %f %f", &x, &y, &r);

	printf("Enter point coordinates (x1, y1): ");
	scanf("%f %f", &x1, &y1);

	d = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));

	if (d < r) 
	{
		printf("Point lies inside the circle\n");
    } else if (d == r)
    {
	    printf("Point lies on the circle\n");
    } else
    {
	    printf("Point lies outside the circle\n");
    }
    return 0;
}
