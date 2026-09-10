#include <stdio.h>

int main() {

	int l, b, area, peri;

	printf("Enter length and breadth: ");
	scanf("%d %d", &l, &b);

	area = l * b;
	peri = 2 * (l + b);

	if (area > peri) 
	{
		prntf("Area is greater than perimeter\n");
	} else 
	{
		printf("Area is not greater than perimeter\n");
	}

	return 0;
}
