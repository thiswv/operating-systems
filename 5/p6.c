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
  } else {
    int status;
    int wc = waitpid(rc, &status, 0);
    if (wc == -1) {
      printf("fail\n");
    } else {
      if (WIFEXITED(status)) {  //WIFEXITED(status)：这个宏用于检查子进程是否正常终止。
        int exit_status = WEXITSTATUS(status);
        //WEXITSTATUS(status)：如果子进程正常终止，即 WIFEXITED(status) 返回真，你可以使用这个宏来获取子进程的退出状态（也称为返回状态）。
        // 0正常返回
        printf("Parent %d - Child %d has terminated with exit status: %d\n", getpid(), wc, exit_status);
      }
    }
  }

  return 0;
}