#include <stdio.h>

int main ()  {
  int a = 0;
  for ( int i = 1; i <= 3; i++ )  {
    for ( int j = 1; j <= 3; j++ )  {
      for ( int k = 1; k <= 3; k++ )  {
        printf("%d%d%d \n", i, j, k );
        a++;
      }
    }
  }
  printf("\n==================================\nNumber of combinations are: %d\n", a);
  return 0;
}