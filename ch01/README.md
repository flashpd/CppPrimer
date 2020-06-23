## Exercise 1.1

> 查阅你使用的编译器文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

* [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions)
* [为 Visual Studio C++项目创建的文件类型](https://docs.microsoft.com/zh-cn/cpp/build/reference/file-types-created-for-visual-cpp-projects?redirectedfrom=MSDN&view=vs-2019)
* [File Types Created for Visual Studio C++ Projects](https://docs.microsoft.com/en-us/cpp/build/reference/file-types-created-for-visual-cpp-projects?redirectedfrom=MSDN&view=vs-2019)



## Exercise 1.2

>



## Exercise 1.3

> 编写程序，在标准输出上打印Hello, World。

```c++
#include <iostream>

int main()
{
    std::cout << "Hello, World";
    return 0;
}
```



## Exercise 1.4

> 编写程序使用乘法运算符*，来打印两个数的积。

```c++
#include <iostream>

int main()
{
    std::cout << "Enter two numbers." << std::endl;
    int a, b;
    std::cin >> a >> b;
    std::cout << a << " * " << b << " = " << a * b << std::endl;

    return 0;
}
```



## Exercise 1.5

> 重写程序，将每个运算对象的打印放在一条独立的语句中。

```c++
#include <iostream>

int main()
{
    std::cout << "Enter two numbers." << std::endl;
    int a, b;
    std::cin >> a >> b;
    std::cout << a;
    std::cout << " * ";
    std::cout << b;
    std::cout << " = ";
    std::cout << a * b;
    std::cout << std::endl;

    return 0;
}
```



## Exercise 1.6

> 解释下列程序片段是否合法。

```c++
    std::cout << "The sum of " << v1;
              << " and " << v2;
              << " is " << v1 + v2 << std::endl;
```

不合法。修正后代码 如下：

```c++
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
```



## Exercise 1.7

> 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

```c++
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/

int main()
{
    return 0;
}
```



## Exercise 1.8

> 指出下列哪些输出语句是合法的（如果有的话）

```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

1、2、4是合法的



## Exercise 1.9

> 使用while循环实现50到100的整数相加

```c++
#include <iostream>

int main()
{
    int sum = 0, num = 50;
    while (num <= 100)
    {
        sum += num;
        num += 1;
    }
    std::cout << sum << std::endl;

    return 0;
}
```



## Exercise 1.10

```c++
#include <iostream>

int main()
{
    int i = 10;
    while (i >= 0)
    {
        std::cout << i-- << " ";
    }
    std::cout << std::endl;

    return 0;
}
```



## Exercise 1.11

```c++
#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;

    while (a <= b)
    {
        std::cout << a << " ";
        ++a;
    }
    std::cout << std::endl;

    return 0;
}
```



## Exercise 1.12

```c++
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

结果是：0



## Exercise 1.13

Ex1.9

```
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << sum << std::endl;

    return 0;
}

```

Ex1.10

```c++
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Ex1.11

```c++
#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int a, b;
    std::cin >> a >> b;
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i <= b; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```



## Exercise 1.14

> 对比for循环和while循环的优缺点。

emmm，for是可以直接在括号内控制循环次数，定义规则，while只需要设置条件。优缺点自行查阅。



## Exercise 1.15

> 编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。

语法错误（syntax error）

```c++
int main()
{
    return 0
}
```

类型错误（type error）

```c++
#include <iostream>

int main()
{
    int a = "asd";
    std::cout << a << std::endl;
    return 0;
}
```

声明错误（declaration error）

```c++
#include <iostream>

int main()
{
    cout << "Hello, World" << std::endl;
    return 0;
}
```



## Exercise 1.16

> 编写程序，从cin读取一组数，输出其和。

```c++
#include <iostream>

int main()
{
    int sum = 0;
    for (int i; std::cin >> i; )
    {
        sum += i;
        std::cout << sum << std::endl;
    }
    return 0;
}
```



## Exercise 1.17

如果输入的值都相等，则结果为一行，显示出这个数字出现了多少次；

如果输入的值都不想等，则结果出现的行数和输入的数字个数一样。



## Exercise 1.18



## Exercise 1.19

> 改写练习1.11的代码，使其能处理用户输入的第一个数字比第二个数字小的情况。

```c++
#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (a <= b)
    {
        std::cout << a << " ";
        ++a;
    }
    std::cout << std::endl;

    return 0;
}
```



## Exercise 1.20

> 读取一组书籍销售记录，将每条记录打印到标准输出上。



## Exercise 1.21

> 读取两个ISBN相同的Sales_item对象，输出他们的和。



## Exercise 1.22

> 读取多个具有相同ISBN的销售记录，输出所有记录的和。



## Exercise 1.23

> 读取多条销售记录，并统计每个ISBN有几条销售记录。

## Exercise 1.24

> 输入表示多个ISBN的多条销售记录

## Exercise 1.25