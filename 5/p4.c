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
    char* myargc[3];
    myargc[0] = strdup("ls");
    myargc[1] = strdup("p4.c");
    myargc[2] = NULL;
    execvp(myargc[0], myargc);
    printf("error\n");
  } else {
    int wc = wait(NULL);
    printf("parents\n");
  }

  return 0;
}