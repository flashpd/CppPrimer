### 练习 8.1

> 编写函数，接受一个`istream&`参数，返回值类型也是`istream&`。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

```cpp
std::istream &func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}
```



### 练习 8.2

> 测试函数，调用参数为`cin`

```cpp
#include <iostream>

std::istream &func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istream &is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
```



### 练习 8.3

> 什么情况下，下面的`while`循环会终止？

```cpp
while (cin >> i) /*  ...    */
```

当`badbit`、`failbit`、`eofbit`中任意一个被置位，那么检测流状态的条件会失败。



### 练习 8.4

> 编写函数，以读模式打开一个文件，将其内容读入到一个`string`的`vector`中，将每一行作为一个独立的元素存于`vector`中。

```cpp
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void ReadFileToVec(const string &fileName, vector<string> &vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (getline(ifs, buf))
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    ReadFileToVec("text.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}
```

