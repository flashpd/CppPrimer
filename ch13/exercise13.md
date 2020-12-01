### 练习 13.1

> 拷贝构造函数是什么？什么时候使用它？

如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数。当使用拷贝初始化时，我们会用到拷贝构造函数。



### 练习 13.2

>解释为什么下面的声明是非法的：
>
>```cpp
>Sales_data::Sales_data(Sales_data rhs);
>```

参数类型应该是引用类型



### 练习 13.3

> 当我们拷贝一个`StrBlob`时，会发生什么？拷贝一个`StrBlobPtr`呢？

（此类在书本404页）



### 练习 13.4

> 假定 `Point` 是一个类类型，它有一个`public`的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
>
> ```cpp
> Point global;
> Point foo_bar(Point arg) // 1
> {
> 	Point local = arg, *heap = new Point(global); // 2: Point local = arg,  3: Point *heap = new Point(global) 
> 	*heap = local; 
> 	Point pa[4] = { local, *heap }; // 4, 5
> 	return *heap;  // 6
> }
> ```

- 第一处是：将一个对象作为实参传递给一个非引用类型的形参
- 第二、三处：使用`=`
- 第四、五处：用花括号列表初始化一个数组中的元素或一个聚合类中的成员
- 第六处：从一个返回类型为非引用类型的函数返回一个对象

### 练习 13.5

> 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的`string`，并将对象拷贝到`ps`所指向的位置，而不是拷贝ps本身：
>
> ```cpp
> class HasPtr {
> public:
> 	HasPtr(const std::string& s = std::string()):
> 		ps(new std::string(s)), i(0) { }
> private:
> 	std::string *ps;
> 	int i;
> }
> ```

```cpp
#include <iostream>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}

private:
    string *ps;
    int i;
};
```



### 练习 13.6

> 拷贝赋值运算符是什么？什么时候使用它？合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？

拷贝赋值运算符是一个名为`operator=`的函数。当赋值运算发生时就会用到它。合成拷贝赋值运算符可以用来进制该类型对象的赋值。如果一个类未定义自己的拷贝赋值运算符，编译器会为其生成一个合成拷贝赋值运算符。



### 练习 13.7

> 当我们将一个 `StrBlob` 赋值给另一个 `StrBlob` 时，会发生什么？赋值 `StrBlobPtr` 呢？

会发生浅层复制



### 练习 13.8

> 为13.1.1节练习13.5中的 `HasPtr` 类编写赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到`ps`指向的位置。

```cpp
#include <iostream>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &rhs_hp)
    {
        if (this != &rhs_hp)
        {
            string *temp_ps = new string(*rhs_hp.ps);
            delete ps;
            ps = temp_ps;
            i = rhs_hp.i;
        }
    }

private:
    string *ps;
    int i;
};
```

