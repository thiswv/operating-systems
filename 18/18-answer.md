第1题
python3 paging-linear-translate.py -P 1k -a 1m -p 512m -v -n 0
[    1023]  0x00000000             1024项

python3 paging-linear-translate.py -P 1k -a 2m -p 512m -v -n 0
[    2047]  0x00000000             2048项

python3 paging-linear-translate.py -P 1k -a 4m -p 512m -v -n 0
[    4095]  0x8002e298             4096项

地址空间越大，页表越大，页表项越多

python3 paging-linear-translate.py -P 1k -a 1m -p 512m -v -n 0
1024项

python3 paging-linear-translate.py -P 2k -a 1m -p 512m -v -n 0
[     511]  0x00000000             512项

python3 paging-linear-translate.py -P 4k -a 1m -p 512m -v -n 0
[     255]  0x8001fb27             256项

页越大，页表越小       页越大，就是页面变大

为什么不使用很大的页呢，因为页越大，分配的空间越大，可能造成的浪费就越大


第2题
python3 paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 0 -c
ARG seed 0
ARG address space size 16k
ARG phys mem size 32k
ARG page size 1k
ARG verbose True
ARG addresses -1


The format of the page table is simple:
The high-order (left-most) bit is the VALID bit.
  If the bit is 1, the rest of the entry is the PFN.
  If the bit is 0, the page is not valid.
Use verbose mode (-v) if you want to print the VPN # by
each entry of the page table.

Page Table (from entry 0 down to the max size)
  [       0]  0x00000000
  [       1]  0x00000000
  [       2]  0x00000000
  [       3]  0x00000000
  [       4]  0x00000000
  [       5]  0x00000000
  [       6]  0x00000000
  [       7]  0x00000000
  [       8]  0x00000000
  [       9]  0x00000000
  [      10]  0x00000000
  [      11]  0x00000000
  [      12]  0x00000000
  [      13]  0x00000000
  [      14]  0x00000000
  [      15]  0x00000000

Virtual Address Trace
  VA 0x00003a39 (decimal:    14905) -->  Invalid (VPN 14 not valid)
  VA 0x00003ee5 (decimal:    16101) -->  Invalid (VPN 15 not valid)
  VA 0x000033da (decimal:    13274) -->  Invalid (VPN 12 not valid)
  VA 0x000039bd (decimal:    14781) -->  Invalid (VPN 14 not valid)
  VA 0x000013d9 (decimal:     5081) -->  Invalid (VPN 4 not valid)

分析一个
0x00003a39   转化为二进制 11100110000110 
-P 1k -a 16k  前提 页面大小 1k   10位二进制    地址空间 16k   14位二进制

页表号     偏移量
1110      01 1000 0110
页表号  14  查表发现对应的物理内存无效

显然可以知道，分配给地址空间的页数越多，分配成功的概率越大

python3 paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 100 -c
ARG seed 0
ARG address space size 16k
ARG phys mem size 32k
ARG page size 1k
ARG verbose True
ARG addresses -1


The format of the page table is simple:
The high-order (left-most) bit is the VALID bit.
  If the bit is 1, the rest of the entry is the PFN.
  If the bit is 0, the page is not valid.
Use verbose mode (-v) if you want to print the VPN # by
each entry of the page table.

如 100% 的
Page Table (from entry 0 down to the max size)
  [       0]  0x80000018
  [       1]  0x80000008
  [       2]  0x8000000c
  [       3]  0x80000009
  [       4]  0x80000012
  [       5]  0x80000010
  [       6]  0x8000001f
  [       7]  0x8000001c
  [       8]  0x80000017
  [       9]  0x80000015
  [      10]  0x80000003
  [      11]  0x80000013
  [      12]  0x8000001e
  [      13]  0x8000001b
  [      14]  0x80000019
  [      15]  0x80000000

Virtual Address Trace
  VA 0x00002e0f (decimal:    11791) --> 00004e0f (decimal    19983) [VPN 11]
  VA 0x00001986 (decimal:     6534) --> 00007d86 (decimal    32134) [VPN 6]
  VA 0x000034ca (decimal:    13514) --> 00006cca (decimal    27850) [VPN 13]
  VA 0x00002ac3 (decimal:    10947) --> 00000ec3 (decimal     3779) [VPN 10]
  VA 0x00000012 (decimal:       18) --> 00006012 (decimal    24594) [VPN 0]


第3题
python3 paging-linear-translate.py -P 8 -a 32 -p 1024 -v -s 1
python3 paging-linear-translate.py -P 8k -a 32k -p 1m -v -s 2 -c
python3 paging-linear-translate.py -P 1m -a 256m -p 512m -v -s 3 -c

三种情况都没有错误，但参数都不太现实
首先1 页面，物理内存，地址空间都太小了。
对于2 页面和地址空间太接近了，只能容纳4个页。
对于3 页太大了，1m的话，内存会有太多的浪费。


第4题
python3 paging-linear-translate.py -P 2k -a 1k -p 1k -v -s 3 -c
ARG seed 3
ARG address space size 1k
ARG phys mem size 1k
ARG page size 2k
ARG verbose True
ARG addresses -1

Error: physical memory size must be GREATER than address space size (for this simulation)

可以有多种方式让程序无法工作，简单的想法就是让页面大小，大于地址空间和物理内存


