#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int rc = fork();
  if (rc < 0) {
    printf("error\n");
  } else if (rc == 0) {
    printf("son   %d\n", getpid());
    //int wc = wait(NULL);
    //printf("son wait   %d\n", wc);
  } else {
    int wc = wait(NULL);
    printf("parents %d\n", wc);
    //rintf("1\n");
  }

  return 0;
}