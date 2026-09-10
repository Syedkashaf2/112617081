#include <stdio.h>

int main()

{
	float temp_c , temp_f;
	printf("Enter the temprature in Fahrenheit : ");
	scanf("%f", & temp_f);

	temp_c = (temp_f - 32) * (5.0/9.0);

	printf("The temprature in Centigrate : %.2f\n", temp_c);

	return 0;
}
