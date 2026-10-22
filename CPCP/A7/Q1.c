#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Multiplication not possible.\n");
        return 0;
    }

    int a[r1][c1], b[r2][c2], result[r1][c2];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Output Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
