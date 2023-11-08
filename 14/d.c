#include <stdio.h>
#include <stdlib.h>

int main()
{
  int* a = (int*)malloc(100 * sizeof(int));

  free(a + 20);

  return 0;
}