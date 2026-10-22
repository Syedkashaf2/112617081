#include <stdio.h>

int main() {
    int n, isIdentity = 1;

    printf("Enter matrix order (N x N): ");
    scanf("%d", &n);

    int mat[n][n];
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("The matrix is :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            if (i != j && mat[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity)
        printf("The matrix is an identity matrix.\n");
    else
        printf("The matrix is not an identity matrix.\n");

    return 0;
}
