#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    int s1, s2;

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter x3, y3: ");
    scanf("%d %d", &x3, &y3);

    s1 = (y2 - y1) * (x3 - x2);
    s2 = (y3 - y2) * (x2 - x1);

    if (s1 == s2) {
        printf("Points fall on one straight line\n");
    } else {
        printf("Points do not fall on one straight line\n");
    }

    return 0;
}
