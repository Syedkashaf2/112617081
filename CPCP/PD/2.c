#include <stdio.h>
int main()  {

  int row_1 = 2,column_1 = 3,row_2 = 3, column_2 = 2;
  int a[row_1][column_1], b[row_2][column_2], c[row_1][column_2];


  for (int i = 0; i < row_1; i++) {
    for(int j = 0; j < column_1; j++) {
      printf("Enter a%d%d\n", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < row_1; i++) {
    for(int j = 0; j < column_1; j++) {
      printf("Enter a%d%d\n", i + 1, j + 1);
      scanf("%d", &b[i][j]);
    }
  }

return 0;
}
