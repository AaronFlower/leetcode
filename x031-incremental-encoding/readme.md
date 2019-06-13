## Incremental encoding, also known as front compression, back compression, or front coding

### C++ 文件操作

一般的文件类型主要有两种: ASCII 文件和二进制文件。无论是那一种文件，我在作为一个读者时都需要知道文件的模式。在操作 ASCII 文件时一般的对于一行可以用 `getline()` 来获取。而用空白符(空格，\t, \n) 分隔的数字可以直接 `>>` 操作符来读取。

而对于二进制文件来讲，则需要严格的协议。每一个数据的长度都需要有严格的定义，对于字符串来讲我也需要用特定字节来保存后继的长度。


### fstream API

两进制文件读写都需要指定长度，这样才能制定协议。

- `file.peek()` 该函数可以窥探文件是否到达了文件尾。
- `file.read(char *p, int len)`
- `file.write(char *p, int len)`
