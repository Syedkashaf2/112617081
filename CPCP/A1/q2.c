#include <stdio.h>

int main()
{
	float km, m, f, in, cm;
	printf("Enter the distance in km : ");

	scanf("%f" , & km);

	m  = km *1000;
	cm = m * 100;
	in = cm/2.54;
      	f  = 12 * in; 	

	printf("Distance in Meters is : %.2f \n", m);
	printf("Distance in feets is  : %.2f \n", f);
	printf("Distance in Meters is : %.2f \n", in);
	printf("Distance in Meters is : %.2f \n", cm);

	return 0;
}

