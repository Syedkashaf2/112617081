#include <stdio.h>

int main()  {
  int n;
  printf("ENTER THE SIZE OF THE ARRAY : ");
  scanf("%d", &n);
  int a[n], num, f;
  printf("ENTER  %d ARRAY ELEMENT : ", n);
  for ( int i = 0; i < n; i++)  {
    scanf("%d", &a[i]);
  }
    printf("ENTER THE NUMBER : ");
    scanf("%d", &num);
  for( int i = 0; i < n; i++ )  {
    if ( a[i] == num ) {
      f++;
    }
  }
  printf("FREQUENCY OF %d IS : %d\n", num, f);
  return 0;
}
