#include <stdio.h>

int main() {
    int cur, join, diff;

    printf("Enter current year and joining year: ");
    scanf("%d %d", &cur, &join);

    diff = cur - join;

    if (diff > 3) {
        printf("Bonus of Rs. 2500 awarded\n");
    }

    return 0;
}
