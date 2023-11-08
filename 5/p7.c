#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  close(STDOUT_FILENO);
  printf("1\n");
}