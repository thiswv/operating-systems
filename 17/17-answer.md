* **第1题**
```
python3 malloc.py flag -n 10 -H 0 -p BEST -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 4 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1015 sz:1 ][ addr:1016 sz:84 ]

注意不需要内存对齐，他要多少直接给就行。
空闲列表越来越多，但还是有可能被使用到。
```


* **第2题**
```
python3 malloc.py flag -n 10 -H 0 -p WORST -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy WORST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1016 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1024 sz:76 ]

Free(ptr[3])
returned 0
Free List [ Size 5 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1024 sz:76 ]

ptr[4] = Alloc(2) returned 1024 (searched 5 elements)
Free List [ Size 5 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1026 sz:74 ]

ptr[5] = Alloc(7) returned 1026 (searched 5 elements)
Free List [ Size 5 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1033 sz:67 ]
空闲列表越来越多，但小的列表基本不会被再次使用，都去找大的内存空间了。
```

* **第3题**
```
python3 malloc.py flag -n 10 -H 0 -p FIRST -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 1 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 3 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1015 sz:1 ][ addr:1016 sz:84 ]
查找变得更快，其次小区间的利用率比worst更高
```


* **第4题**
```
python3 malloc.py flag -n 10 -H 0 -p FIRST -s 0 -c -l SIZESORT-
python3 malloc.py flag -n 10 -H 0 -p FIRST -s 0 -c -l SIZESORT+
python3 malloc.py flag -n 10 -H 0 -p FIRST -s 0 -c -l ADDRSORT

不管怎么排序，对BEST和WORST都没有任何的影响，因为它们不管怎么样都要遍历全部的空间来寻找合适的值。
发现地址空间递减排序对  FIRST首次匹配是有影响的。都去用大空间了。
对后面的小空间基本不会去用了。
递增和按地址对首次排序也都有影响。
python3 malloc.py flag -n 10 -H 0 -p FIRST -s 0 -c -l SIZESORT-
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder SIZESORT-
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1003 sz:97 ][ addr:1000 sz:3 ]

ptr[1] = Alloc(5) returned 1003 (searched 1 elements)
Free List [ Size 2 ]: [ addr:1008 sz:92 ][ addr:1000 sz:3 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1008 sz:92 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[2] = Alloc(8) returned 1008 (searched 1 elements)
Free List [ Size 3 ]: [ addr:1016 sz:84 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1016 sz:84 ][ addr:1008 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[3] = Alloc(8) returned 1016 (searched 1 elements)
Free List [ Size 4 ]: [ addr:1024 sz:76 ][ addr:1008 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

Free(ptr[3])
returned 0
Free List [ Size 5 ]: [ addr:1024 sz:76 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[4] = Alloc(2) returned 1024 (searched 1 elements)
Free List [ Size 5 ]: [ addr:1026 sz:74 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[5] = Alloc(7) returned 1026 (searched 1 elements)
Free List [ Size 5 ]: [ addr:1033 sz:67 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]
```


* **第5题**
```
碎片的空间越来越多，最后基本分配不了空间
有合并的话，可以充分分配。

有合并的情况下最后的size 为 100 
python3 malloc.py flag -n 1000 -H 0 -p WORST -s 0 -c -C
Free(ptr[516])
returned 0
Free List [ Size 1 ]: [ addr:1000 sz:100 ]

没有 -C 最后的size都是1
python3 malloc.py flag -n 1000 -H 0 -p WORST -s 0 -c
ptr[828] = Alloc(9) returned -1 (searched 100 elements)
Free List [ Size 100 ]: [ addr:1000 sz:1 ][ addr:1001 sz:1 ][ addr:1002 sz:1 ][ addr:1003 sz:1 ][ addr:1004 sz:1 ][ addr:1005 sz:1 ][ addr:1006 sz:1 ][ addr:1007 sz:1 ][ addr:1008 sz:1 ][ addr:1009 sz:1 ][ addr:1010 sz:1 ][ addr:1011 sz:1 ][ addr:1012 sz:1 ][ addr:1013 sz:1 ][ addr:1014 sz:1 ][ addr:1015 sz:1 ][ addr:1016 sz:1 ][ addr:1017 sz:1 ][ addr:1018 sz:1 ][ addr:1019 sz:1 ][ addr:1020 sz:1 ][ addr:1021 sz:1 ][ addr:1022 sz:1 ][ addr:1023 sz:1 ][ addr:1024 sz:1 ][ addr:1025 sz:1 ][ addr:1026 sz:1 ][ addr:1027 sz:1 ][ addr:1028 sz:1 ][ addr:1029 sz:1 ][ addr:1030 sz:1 ][ addr:1031 sz:1 ][ addr:1032 sz:1 ][ addr:1033 sz:1 ][ addr:1034 sz:1 ][ addr:1035 sz:1 ][ addr:1036 sz:1 ][ addr:1037 sz:1 ][ addr:1038 sz:1 ][ addr:1039 sz:1 ][ addr:1040 sz:1 ][ addr:1041 sz:1 ][ addr:1042 sz:1 ][ addr:1043 sz:1 ][ addr:1044 sz:1 ][ addr:1045 sz:1 ][ addr:1046 sz:1 ][ addr:1047 sz:1 ][ addr:1048 sz:1 ][ addr:1049 sz:1 ][ addr:1050 sz:1 ][ addr:1051 sz:1 ][ addr:1052 sz:1 ][ addr:1053 sz:1 ][ addr:1054 sz:1 ][ addr:1055 sz:1 ][ addr:1056 sz:1 ][ addr:1057 sz:1 ][ addr:1058 sz:1 ][ addr:1059 sz:1 ][ addr:1060 sz:1 ][ addr:1061 sz:1 ][ addr:1062 sz:1 ][ addr:1063 sz:1 ][ addr:1064 sz:1 ][ addr:1065 sz:1 ][ addr:1066 sz:1 ][ addr:1067 sz:1 ][ addr:1068 sz:1 ][ addr:1069 sz:1 ][ addr:1070 sz:1 ][ addr:1071 sz:1 ][ addr:1072 sz:1 ][ addr:1073 sz:1 ][ addr:1074 sz:1 ][ addr:1075 sz:1 ][ addr:1076 sz:1 ][ addr:1077 sz:1 ][ addr:1078 sz:1 ][ addr:1079 sz:1 ][ addr:1080 sz:1 ][ addr:1081 sz:1 ][ addr:1082 sz:1 ][ addr:1083 sz:1 ][ addr:1084 sz:1 ][ addr:1085 sz:1 ][ addr:1086 sz:1 ][ addr:1087 sz:1 ][ addr:1088 sz:1 ][ addr:1089 sz:1 ][ addr:1090 sz:1 ][ addr:1091 sz:1 ][ addr:1092 sz:1 ][ addr:1093 sz:1 ][ addr:1094 sz:1 ][ addr:1095 sz:1 ][ addr:1096 sz:1 ][ addr:1097 sz:1 ][ addr:1098 sz:1 ][ addr:1099 sz:1 ]

在不合并的情况下，使用不同排序没有大作用，都是失败
例如
python3 malloc.py flag -n 1000 -H 0 -p WORST -s 0 -c -l SIZESORT-
ptr[828] = Alloc(9) returned -1 (searched 100 elements)
Free List [ Size 100 ]: [ addr:1090 sz:1 ][ addr:1087 sz:1 ][ addr:1039 sz:1 ][ addr:1014 sz:1 ][ addr:1002 sz:1 ][ addr:1020 sz:1 ][ addr:1055 sz:1 ][ addr:1095 sz:1 ][ addr:1084 sz:1 ][ addr:1045 sz:1 ][ addr:1096 sz:1 ][ addr:1032 sz:1 ][ addr:1063 sz:1 ][ addr:1015 sz:1 ][ addr:1023 sz:1 ][ addr:1064 sz:1 ][ addr:1058 sz:1 ][ addr:1003 sz:1 ][ addr:1004 sz:1 ][ addr:1011 sz:1 ][ addr:1081 sz:1 ][ addr:1042 sz:1 ][ addr:1071 sz:1 ][ addr:1072 sz:1 ][ addr:1005 sz:1 ][ addr:1088 sz:1 ][ addr:1046 sz:1 ][ addr:1097 sz:1 ][ addr:1085 sz:1 ][ addr:1012 sz:1 ][ addr:1037 sz:1 ][ addr:1000 sz:1 ][ addr:1008 sz:1 ][ addr:1001 sz:1 ][ addr:1013 sz:1 ][ addr:1038 sz:1 ][ addr:1086 sz:1 ][ addr:1047 sz:1 ][ addr:1089 sz:1 ][ addr:1073 sz:1 ][ addr:1028 sz:1 ][ addr:1030 sz:1 ][ addr:1021 sz:1 ][ addr:1049 sz:1 ][ addr:1033 sz:1 ][ addr:1035 sz:1 ][ addr:1016 sz:1 ][ addr:1056 sz:1 ][ addr:1051 sz:1 ][ addr:1077 sz:1 ][ addr:1043 sz:1 ][ addr:1082 sz:1 ][ addr:1093 sz:1 ][ addr:1098 sz:1 ][ addr:1006 sz:1 ][ addr:1079 sz:1 ][ addr:1061 sz:1 ][ addr:1069 sz:1 ][ addr:1040 sz:1 ][ addr:1065 sz:1 ][ addr:1091 sz:1 ][ addr:1067 sz:1 ][ addr:1053 sz:1 ][ addr:1009 sz:1 ][ addr:1024 sz:1 ][ addr:1026 sz:1 ][ addr:1018 sz:1 ][ addr:1075 sz:1 ][ addr:1059 sz:1 ][ addr:1076 sz:1 ][ addr:1060 sz:1 ][ addr:1019 sz:1 ][ addr:1027 sz:1 ][ addr:1025 sz:1 ][ addr:1010 sz:1 ][ addr:1054 sz:1 ][ addr:1068 sz:1 ][ addr:1092 sz:1 ][ addr:1066 sz:1 ][ addr:1041 sz:1 ][ addr:1070 sz:1 ][ addr:1062 sz:1 ][ addr:1080 sz:1 ][ addr:1007 sz:1 ][ addr:1099 sz:1 ][ addr:1083 sz:1 ][ addr:1094 sz:1 ][ addr:1044 sz:1 ][ addr:1078 sz:1 ][ addr:1052 sz:1 ][ addr:1057 sz:1 ][ addr:1017 sz:1 ][ addr:1036 sz:1 ][ addr:1034 sz:1 ][ addr:1050 sz:1 ][ addr:1022 sz:1 ][ addr:1031 sz:1 ][ addr:1029 sz:1 ][ addr:1074 sz:1 ][ addr:1048 sz:1 ]
```

* **第6题**
```
python3 malloc.py flag -n 1000 -H 0 -p BEST -s 0 -c -P 99
ptr[982] = Alloc(4) returned -1 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1015 sz:1 ]

ptr[983] = Alloc(6) returned -1 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1015 sz:1 ]

ptr[984] = Alloc(7) returned -1 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1015 sz:1 ]

ptr[985] = Alloc(1) returned 1015 (searched 1 elements)
Free List [ Size 0 ]: 

ptr[986] = Alloc(4) returned -1 (searched 0 elements)
Free List [ Size 0 ]: 
P 越高，空间基本都不够分
```


* **第7题**
```
python3 malloc.py -A +5,+5,+5,+5,+5,-0,-1,-2,-3,-4 -c -S 35
seed 0
size 35
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList +5,+5,+5,+5,+5,-0,-1,-2,-3,-4
compute True

ptr[0] = Alloc(5) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1005 sz:30 ]

ptr[1] = Alloc(5) returned 1005 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1010 sz:25 ]

ptr[2] = Alloc(5) returned 1010 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1015 sz:20 ]

ptr[3] = Alloc(5) returned 1015 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1020 sz:15 ]

ptr[4] = Alloc(5) returned 1020 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1025 sz:10 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:5 ][ addr:1025 sz:10 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:5 ][ addr:1005 sz:5 ][ addr:1025 sz:10 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:5 ][ addr:1005 sz:5 ][ addr:1010 sz:5 ][ addr:1025 sz:10 ]

Free(ptr[3])
returned 0
Free List [ Size 5 ]: [ addr:1000 sz:5 ][ addr:1005 sz:5 ][ addr:1010 sz:5 ][ addr:1015 sz:5 ][ addr:1025 sz:10 ]

Free(ptr[4])
returned 0
Free List [ Size 6 ]: [ addr:1000 sz:5 ][ addr:1005 sz:5 ][ addr:1010 sz:5 ][ addr:1015 sz:5 ][ addr:1020 sz:5 ][ addr:1025 sz:10 ]
多进行几次小的空间分配
```