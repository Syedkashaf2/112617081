#include <stdio.h>

int main() 
{
	int r, s, a;


	printf("Enter age of Ram, Shyam, Ajay seperated by space:");

	scanf("%d %d %d", &r, &s, &a);

	if (r < s && r < a) {
        printf("Ram is the youngest\n");
	} else if (s < a) 
	{
		printf("Shyam is thr youngest\n");
	} else 
	{
		printf("Ajay is the youest\n");
	}

    return 0;
}
