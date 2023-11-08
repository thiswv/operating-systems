#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int x = 100;

  int rc = fork();
  if (rc < 0) {
    printf("error\n");
    exit(1);
  } else if (rc == 0) {
    x = 10;
    printf("子进程输出x   %d\n", x);
  } else {
    printf("主进程输出x   %d\n", x);
  }

  return 0;
}