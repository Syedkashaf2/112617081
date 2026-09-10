#include <stdio.h>

int main()
{
	float a, b, c, d, e, total, percentage;

	printf("Enter the marks obtained in sub1 : ");
	scanf("%f", & a);

	printf("Enter the marks obtained in sub2 : ");
        scanf("%f", & b);
	
	printf("Enter the marks obtained in sub3 : ");
        scanf("%f", & c);
	
	printf("Enter the marks obtained in sub4 : ");
        scanf("%f", & d);
	
	printf("Enter the marks obtained in sub5 : ");
        scanf("%f", & e);

	total = a + b + c + d + e;
	percentage = (total/500) * 100;

	printf("Total marks obtained in 5 subjects is : %.2f\n", total);

	printf("Percentage of marks obtained in 5 subjects is : %.2f\n", percentage);

	return 0;
}
