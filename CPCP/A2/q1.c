#include <stdio.h>

int main() {
    int qty;
    float price, tot, dis;

    printf("Enter quantity and price: ");
    scanf("%d %f", &qty, &price);

    tot = qty * price;

    if (qty > 1000) {
        dis = tot * 0.10;
        tot = tot - dis;
    }

    printf("Total expense = %.2f\n", tot);
    return 0;
}
