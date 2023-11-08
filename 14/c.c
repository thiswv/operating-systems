#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  int* a = (int*)malloc(100 * sizeof(int));

  // a[100] = 0;

  free(a);
  
  printf("a[90] %d\n", a[90]);
  printf("a[100] %d\n", a[100]);

  return 0;
}