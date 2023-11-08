#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define PAGESIZE 4096

int main(int argc, char* argv[]) 
{
  if (argc != 3) {
    fprintf(stderr, "error parameters!");
    exit(0);
  }

  struct timeval start, end;
  int NUMPAGES = atoi(argv[1]);
  int trynum = atoi(argv[2]);
  int jump = PAGESIZE / sizeof(int);
  int arr[NUMPAGES * jump];

  memset(arr, 0, sizeof(arr));  //第7题,自己初始化可以抵消冷启动的开销
  /*
  数组 arr 没有被初始化，那么在第一次访问它的时候可能会非常耗时，
  因为操作系统或编程语言的运行时系统需要分配内存并将其初始化为默认值。这种操作通常被称为"冷启动"开销。
  */

  gettimeofday(&start, NULL);
  for (int j = 0; j < trynum; j ++) {
    for (int i = 0; i < NUMPAGES * jump; i += jump) {       //为什么是 +jump 因为空间局域性
      arr[i] += 1;
    }
  }

  gettimeofday(&end, NULL);
  printf("%f %ld %ld\n", ((double)end.tv_usec - start.tv_usec) / NUMPAGES / trynum, end.tv_usec, start.tv_usec);
  return 0;
}