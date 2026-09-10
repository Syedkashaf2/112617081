#include <stdio.h>

int main()
{
        int C, D, A, B;

        printf("Enter the C : ");
        scanf("%d", & C);

        printf("Enter the D : ");
        scanf("%d", & D);

	A = C;
	B = D;

	C = B;
	D = A;

        printf("The value of C is : %d\n", C);
        printf("The value of D is : %d\n", D);
        
        return 0;
}


