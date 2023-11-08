#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int fd = open("./p2.output", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
  if (fd == -1) {
    printf("error\n");
    exit(1);
  }

  int rc = fork();
  if (rc < 0) {
    printf("error\n");
    exit(1);
  } else if (rc == 0) {
    char* word = "hello world, I am a child.\n";
    write(fd, word, strlen(word));
    close(fd);
  } else {
    char* word = "hello world, I am parent.\n";
    write(fd, word, strlen(word));
    close(fd);
  }

  return 0;
}
