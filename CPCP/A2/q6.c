#include <stdio.h>

int main() 
{

	int yr;

	printf("Enter year: ");
	scanf("%d", &yr);

	if ((yr % 400 == 0) || (yr % 4 == 0 && yr % 100 != 0)) {
		printf("Leap year\n");
	} else

	{
		printf("Not a leap year\n");
	}
	return 0;
}
