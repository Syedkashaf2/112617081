#include <stdio.h>

int main() {
    int r, s, a;

    printf("Enter ages of Ram, Shyam, Ajay: ");
    scanf("%d %d %d", &r, &s, &a);

    if (r < s && r < a) {
        printf("Ram is the youngest\n");
    } else if (s < a) {
        printf("Shyam is the youngest\n");
    } else {
        printf("Ajay is the youngest\n");
    }

    return 0;
}
