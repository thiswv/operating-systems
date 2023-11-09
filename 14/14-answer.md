* **第1,2,3题**
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int* x = NULL;

  free(x);
  return 0;
}

运行时没有输出
gdb: [Inferior 1 (process 4132) exited normally] 正常输出
valgrind: 
==4137== HEAP SUMMARY:
==4137==     in use at exit: 0 bytes in 0 blocks
==4137==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==4137== 
==4137== All heap blocks were freed -- no leaks are possible
==4137== 
==4137== For lists of detected and suppressed errors, rerun with: -s
==4137== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0
全是0, 没有问题
```

* **第4题**
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int* x = (int*)malloc(sizeof(int));

  return 0;
}

运行时没有输出
gdb: [Inferior 1 (process 4165) exited normally] 正常输出
valgrind:
==4183== HEAP SUMMARY:
==4183==     in use at exit: 4 bytes in 1 blocks
==4183==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==4183== 
==4183== LEAK SUMMARY:
==4183==    definitely lost: 4 bytes in 1 blocks
==4183==    indirectly lost: 0 bytes in 0 blocks
==4183==      possibly lost: 0 bytes in 0 blocks
==4183==    still reachable: 0 bytes in 0 blocks
==4183==         suppressed: 0 bytes in 0 blocks
==4183== Rerun with --leak-check=full to see details of leaked memory
==4183== 
==4183== For lists of detected and suppressed errors, rerun with: -s
==4183== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
在堆上发生内存泄漏, 有4个字节未被清理
```


* **第5题**
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  int* a = (int*)malloc(100 * sizeof(int));

  a[100] = 0;

  return 0;
}

运行时没有输出
gdb: [Inferior 1 (process 4222) exited normally]  正常结束
valgrind: 
==4226== HEAP SUMMARY:
==4226==     in use at exit: 400 bytes in 1 blocks
==4226==   total heap usage: 1 allocs, 0 frees, 400 bytes allocated
==4226== 
==4226== LEAK SUMMARY:
==4226==    definitely lost: 400 bytes in 1 blocks
==4226==    indirectly lost: 0 bytes in 0 blocks
==4226==      possibly lost: 0 bytes in 0 blocks
==4226==    still reachable: 0 bytes in 0 blocks
==4226==         suppressed: 0 bytes in 0 blocks
==4226== Rerun with --leak-check=full to see details of leaked memory
==4226== 
==4226== For lists of detected and suppressed errors, rerun with: -s
==4226== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
堆中有400字节没有被释放
```

* **第6题**
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  int* a = (int*)malloc(100 * sizeof(int));

  free(a);
  
  printf("a[90] %d\n", a[90]);
  printf("a[100] %d\n", a[100]);

  return 0;
}

运行:
a[90] 0
a[100] 0
gdb:
a[90] 0
a[100] 0
[Inferior 1 (process 4248) exited normally]
valgrind:
==4253== Invalid read of size 4
==4253==    at 0x1091B9: main (c.c:13)
==4253==  Address 0x4a501a8 is 360 bytes inside a block of size 400 free'd
==4253==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==4253==    by 0x1091AE: main (c.c:11)
==4253==  Block was alloc'd at
==4253==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==4253==    by 0x10919E: main (c.c:7)
==4253== 
a[90] 0
==4253== Invalid read of size 4
==4253==    at 0x1091D8: main (c.c:14)
==4253==  Address 0x4a501d0 is 0 bytes after a block of size 400 free'd
==4253==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==4253==    by 0x1091AE: main (c.c:11)
==4253==  Block was alloc'd at
==4253==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==4253==    by 0x10919E: main (c.c:7)
==4253== 
a[100] 0
==4253== 
==4253== HEAP SUMMARY:
==4253==     in use at exit: 0 bytes in 0 blocks
==4253==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==4253== 
==4253== All heap blocks were freed -- no leaks are possible
==4253== 
==4253== For lists of detected and suppressed errors, rerun with: -s
==4253== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
两次无效读取错误, 为什么a[100]有答案呢, 可能是没有其他的代码的影响那块内存
```


* **第7题**
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int* a = (int*)malloc(100 * sizeof(int));

  free(a + 20);

  return 0;
}

运行结果 free(): invalid pointer
释放一个无效的指针
不需要工具,直接会报错.
```




