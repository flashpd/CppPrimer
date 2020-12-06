### 练习 6.1

> 实参和形参的区别的什么？

实参是形参的初始值。



### 练习 6.2

> 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
>
> ```cpp
> (a) int f() {
>          string s;
>          // ...
>          return s;
>    }
> (b) f2(int i) { /* ... */ }
> (c) int calc(int v1, int v1) { /* ... */ }
> (d) double square (double x)  return x * x; 
> ```

```cpp
(a) string f() {
         string s;
         // ...
         return s;
   }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x)  { return x * x; }
```



### 练习 6.3

> 编写你自己的`fact`函数，上机检查是否正确。注：阶乘。

```cpp
#include <iostream>

using std::cout;
using std::endl;

int fact(int val)
{
    for (int i = 0; i < 10; ++i)
        val += i;

    return val;
}

int main()
{
    cout << fact(10) << endl;

    return 0;
}
```



### 练习 6.4

> 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

```cpp
#include <iostream>
#include <string>

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    std::string const prompt = "Enter a number within [1, 13) :\n";
    std::string const out_of_range = "Out of range, please try again.\n";
    for (int i; std::cout << prompt, std::cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            std::cout << out_of_range; 
            continue;
        }
        std::cout << fact(i) << std::endl;
    }
}

int main()
{
    interactive_fact();
    return 0;
}
```



### 练习 6.5

> 编写一个函数输出其实参的绝对值。

```cpp
#include <iostream>

int abs(int i)
{
   return i > 0 ? i : -i;
}

int main()
{
   std::cout << abs(-5) << std::endl;
   return 0;
}
```



### 练习 6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。

- 形参定义在函数形参列表
- 局部变量定义在代码块离
- 局部静态变量再程序的执行路径第一次经过对象地暖管一语句时初始化，并且直到程序终止才被销毁。在此期间即使对象所在的函数结束执行也不会对它产生影响

```cpp
// example
size_t count_add(int n)       // n是形参
{
    static size_t ctr = 0;    // ctr是局部静态变量
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i局部变量
      cout << count_add(i) << endl;

    return 0;
}
```



### 练习 6.7

> 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

```cpp
size_t generate()
{
    static size_t ctr = 0;
    return ctr++;
}
```



### 练习 6.16

> 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
>
> ```cpp
> bool is_empty(string& s) { return s.empty(); }
> ```

```cpp
bool is_empty(const string& s) { return s.empty(); }
```



