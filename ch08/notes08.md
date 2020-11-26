# 笔记

## 8.1 IO类

| 头文件   | 类型                                                         |
| -------- | :----------------------------------------------------------- |
| iostream | 从流中读写数据，istream、ostream、iostream、wistream、wostream、wiostream |
| fstream  | 从文件中读写数据，ifstream、ofstream、fstream、wifstream、wofstream、wfstream |
| sstream  | 从string中读写数据，istringstream、ostringstream、stringstream、wistringstream、wostringstream、wstringstream |

标准库定义了一组类型和对象来操纵`wchar_t`类型的数据，宽字符版本的类型和函数的名字以一个 `w`开头

### IO对象无拷贝或赋值

1. 不能将形参或返回类型设置为流类型
2. 进行IO操作的函数通常以引用的方式传递和返回流
3. 读写一个IO对象会改变其状态，因此传递和返回的引用不能是const

### 条件状态

| IO库              | 条件状态                                                     |
| ----------------- | ------------------------------------------------------------ |
| strm::iostate     | strm是一种IO类型。iostate是一种机器相关的类型，提供了表达条件状态的完整功能 |
| strm::badbit      | 指出流已崩溃                                                 |
| strm::failbit     | 指出一个IO操作失败了                                         |
| strm::eofbit      | 指出流到达了文件结束                                         |
| strm::goodbit     | 指出流未处于错误状态。此值保证为零                           |
| s.eof()           | 若流s的eofbit置位，则返回true                                |
| s.fail()          | 若流s的failbit或badbit置位，则返回true                       |
| s.bad()           | 若流s的badbit置位，则返回true                                |
| s.good()          | 若流s处于有效状态，则返回true                                |
| s.clear()         | 若流s中所有条件状态位复位，将流的状态设置为有效。返回void    |
| s.clear(flags)    | 根据flags标志位，将流s中对应条件状态位复位。flags的类型为strm::iostate。返回void |
| s.setstate(flags) | 根据flags标志位，将流s中对应条件状态位置位。flags的类型为strm::iostate。返回void |
| s.rdstate()       | 返回流s的当前条件状态，返回值类型为strm::iostate             |

### 管理输出缓冲

有了缓冲机制，操作系统可以将程序的多个输出操作组合成单一的系统及写操作，由于设备的写操作可能很耗时，允许操作系统将多个输出操作组合为单一的设备写操作可以带来很大的性能提升

缓冲刷新，即数据真正的写到输出设备或文件

刷新缓冲区：

1. `endl`: 输出一个换行，然后刷新缓冲区
2. `flush`: 刷新缓冲区，但不输出任何额外字符
3. `ends`: 向缓冲区插入一个空字符，然后刷新缓冲区
4. `unitbuf`: 告诉流接下来每次写操作之后都进行一次flush操作
5. `nounitbuf`: 重置流，使其恢复使用正常的系统管理的缓冲区刷新机制

当一个输入流被关联到一个输出流时，任何试图从输入流读取数据二点操作都会先刷新关联的输出流。例如`cin`和`cout`。

## 8.2 文件输入输出

| 操作                   | 解释                                                         |
| ---------------------- | ------------------------------------------------------------ |
| fstream fstrm          | 创建一个未绑定的文件流                                       |
| fstream fstrm(s)       | 创建一个fstream，并打开名为s的文件，s可以是string类型，或是一个指向C风格字符串的指针 |
| fstream fstrm(s, mode) | 与上一条相似，但按指定mode打开文件                           |
| fstrm.open(s)          | 打开名为s的文件，并将文件与fstrm绑定                         |
| fstream.close()        | 关闭fstream绑定的文件，返回void                              |
| fstrem.is_open()       | 返回一个bool值，指出与fstream关联的文件是否成功打开且尚未关闭 |



### 文件模式

| 操作   | 解释                         |
| ------ | ---------------------------- |
| in     | 以读方式打开                 |
| out    | 以写方式打开                 |
| app    | 每次写操作前均定位到文件末尾 |
| ate    | 打开文件后立即定位到文件末尾 |
| trunc  | 截断文件                     |
| binary | 以二进制方式进行IO           |



## 8.3 string流

| 特有操作        | 解释                                          |
| --------------- | --------------------------------------------- |
| sstream strm    | strm是一个未绑定的stringstream对象            |
| sstream strm(s) | strm是一个sstream对象，保存string s的一个拷贝 |
| strm.str()      | 返回strm所保存的string的拷贝                  |
| strm.str(s)     | 将string s拷贝到strm中。返回void              |



