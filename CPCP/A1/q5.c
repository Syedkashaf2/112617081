#include <stdio.h>

int main()
{       
        float length, breadth, pi = 3.14, radius, area_r, area_c, circum, parimeter;

        printf("Enter the length : ");
        scanf("%f", & length);

        printf("Enter the breadth : ");
        scanf("%f", & breadth);

        printf("Enter the radius : ");
        scanf("%f", & radius);

        parimeter = length + breadth;
	area_r = length * breadth;
	circum = radius*2*pi;
	area_c = pi* radius*radius;

        printf("Parimeter of the rectangle is : %.2f\n", parimeter);

        printf("Area of the rectangle is : %.2f\n", area_r);
        printf("Area of the circle is : %.2f\n", area_c);
        printf("Area of the rectangle is : %.2f\n", circum);
        
        return 0;
}       

