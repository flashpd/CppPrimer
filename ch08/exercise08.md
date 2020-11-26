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
    ReadFileToVec("8-4.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}
```



### 练习 8.5

> 重写上面的程序，将每个单词作为一个独立的元素进行存储。

```cpp
// 基本同8.4 只需修改while的条件
void ReadFileToVec(const string &fileName, vector<string> &vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}
```



### 练习 8.6

> 重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给`main`。

```cpp
#include <iostream>
#include <fstream>
#include "ex7_26.h"
// #include "ex7_26.cpp"

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}
```



### 练习 8.7

> 修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给`main`函数。

```cpp
#include <iostream>
#include <fstream>
#include "ex7_26.h"
// #include "ex7_26.cpp"

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}
```



### 练习 8.8

> 修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

```cpp
#include <iostream>
#include <fstream>
#include "ex7_26.h"
// #include "ex7_26.cpp"

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}
```



### 练习 8.9

> 使用你为8.1.2节第一个练习所编写的函数打印一个`istringstream`对象的内容。

```cpp
#include <iostream>
#include <sstream>

using namespace std;

istream &func(istream &is)
{
    string buf;
    while (is >> buf)
        cout << buf << endl;
    is.clear();
    return is;
}

int main()
{
    istringstream iss("Hello");
    func(iss);
    return 0;
}
```



### 练习 8.10

> 编写程序，将来自一个文件中的行保存在一个`vector`中。然后使用一个`istringstream`从`vector`读取数据元素，每次读取一个单词。

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ifstream ifs("8-4.txt");
    if (!ifs)
    {
        cerr << "No data?!" << endl;
        return -1;
    }

    vector<string> vecLine;
    string line;
    while (getline(ifs, line))
        vecLine.push_back(line);

    for (auto &s : vecLine)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
            cout << word << endl;
    }

    return 0;
}
```



### 练习 8.11

> 本节的程序在外层`while`循环中定义了`istringstream`对象。如果`record`对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将`record`的定义移到`while`循环之外，验证你设想的修改方法是否正确。

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);

        people.push_back(info);
    }

    for (auto &p : people)
    {
        cout << p.name << " ";
        for (auto &s : p.phones)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}
```



### 练习 8.12

> 我们为什么没有在`PersonInfo`中使用类内初始化？

因为这里只需要聚合类就够了，没必要类内初始化



### 练习 8.13

> 重写本节的电话号码程序，从一个命名文件而非`cin`读取数据

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool vaild(const string &str)
{
    return isdigit(str[0]);
}

string format(const string &str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream ifs("8-13.txt");
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);

        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!vaild(nums)) // 判断是否为无效 如果是则向badNums输入
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }

        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s) "
                 << badNums.str() << endl;
    }

    return 0;
}
```



### 练习 8.14

> 我们为什么将`entry`和`nums`定义为`const auto&`？

它们都是类类型，使用引用可以避免拷贝，它们的值不需要被修改，所以使用const。