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

- 拷贝赋值运算符是一个名为`operator=`的函数。当赋值运算发生时就会用到它。
- 合成拷贝赋值运算符可以用来进制该类型对象的赋值。
- 如果一个类未定义自己的拷贝赋值运算符，编译器会为其生成一个合成拷贝赋值运算符。



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



### 练习 13.9

> 析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？

- 析构函数是类的一个成员函数，名字由波浪号接类名构成。它没有返回值，不接受参数。
- 合成析构函数可被用来阻止该类型的对象被销毁
- 当一个类未定义自己的析构函数时，编译器会被它生成一个合成析构函数



### 练习 13.10

> 当一个 `StrBlob` 对象销毁时会发生什么？一个 `StrBlobPtr` 对象销毁时呢？



### 练习 13.11

> 为前面练习中的 `HasPtr` 类添加一个析构函数。

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

    ~HasPtr()
    {
        delete ps;
    }

private:
    string *ps;
    int i;
};
```



### 练习 13.12

> 在下面的代码片段中会发生几次析构函数调用？
>
> ```cpp
> bool fcn(const Sales_data *trans, Sales_data accum)
> {
> 	Sales_data item1(*trans), item2(accum);
> 	return item1.isbn() != item2.isbn();
> }
> ```

3次`accum`、`item1` 、 `item2`。

- `accum`：变量在离开其作用域时被销毁
- `item1` 和 `item2`：对于临时对象，当创建它的完整表达式结束时被销毁



### 练习 13.13

> 理解拷贝控制成员和构造函数的一个好方法的定义一个简单的类，为该类定义这些成员，每个成员都打印出自己的名字：
>
> ```cpp
> struct X {
> 	X() {std::cout << "X()" << std::endl;}
> 	X(const X&) {std::cout << "X(const X&)" << std::endl;}
> }
> ```
>
> 给 `X` 添加拷贝赋值运算符和析构函数，并编写一个程序以不同的方式使用 `X` 的对象：将它们作为非引用参数传递；动态分配它们；将它们存放于容器中；诸如此类。观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。

```cpp
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

struct X
{
    X() { cout << "X()" << endl; }
    X(const X &) { cout << "X(const X&)" << endl; }
    X &operator=(const X &)
    {
        cout << "X& operator=(const X&)" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void f(const X &rx, X x) // 第二个参数 X x会调用拷贝构造函数和析构函数
{
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); // 调用拷贝构造函数和析构函数
    vec.push_back(x);  // 调用拷贝构造函数和析构函数
}

int main()
{
    X *px = new X; // X()
    f(*px, *px);
    delete px; // ~X()

    return 0;
}
```



### 练习 13.14

> 假定 `numbered` 是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为 `mysn` 的数据成员中。假定 `numbered` 使用合成的拷贝控制成员，并给定如下函数：
>
> ```cpp
> void f (numbered s) { cout << s.mysn < endl; }
> ```
>
> 则下面代码输出什么内容？
>
> ```cpp
> numbered a, b = a, c = b;
> f(a); f(b); f(c);
> ```

输出三个相同的数



### 练习 13.15

> 假定`numbered` 定义了一个拷贝构造函数，能生成一个新的序列号。这会改变上一题中调用的输出结果吗？如果会改变，为什么？新的输出结果是什么？

输出三个完全不同的数



### 练习 13.16

> 如果 `f` 中的参数是 `const numbered&`，将会怎样？这会改变输出结果吗？如果会改变，为什么？新的输出结果是什么？

会输出a，b，c的数



### 练习 13.17

> 分别编写前三题中所描述的 `numbered` 和 `f`，验证你是否正确预测了输出结果。

- 13.14

```cpp
#include <iostream>
#include <random>
using namespace std;

class numbered
{
public:
    numbered();

public:
    int mysn;
};

numbered::numbered()
{
    this->mysn = rand() % 100;
}

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
```



- 13.15

```cpp
#include <iostream>
#include <random>
using namespace std;

class numbered
{
public:
    numbered();
    numbered(const numbered &);

public:
    int mysn;
};

numbered::numbered()
{
    this->mysn = rand() % 100;
}

numbered::numbered(const numbered &rh)
{
    this->mysn = rand() % 100;
}

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
```

- 13.16

```cpp
#include <iostream>
#include <random>
using namespace std;

class numbered
{
public:
    numbered();
    numbered(const numbered &);

public:
    int mysn;
};

numbered::numbered()
{
    this->mysn = rand() % 100;
}

numbered::numbered(const numbered &rh)
{
    this->mysn = rand() % 100;
}

void f(const numbered &s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
```



### 练习 13.18

> 定义一个 `Employee` 类，它包含雇员的姓名和唯一的雇员证号。为这个类定义默认构造函数，以及接受一个表示雇员姓名的 `string` 的构造函数。每个构造函数应该通过递增一个 `static` 数据成员来生成一个唯一的证号。

```cpp
#include <iostream>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(const string &name);

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

int Employee::s_increment = 0;
Employee::Employee()
{
    id_ = s_increment++;
}

Employee::Employee(const string &name)
{
    id_ = s_increment++;
    name_ = name;
}
```



### 练习 13.19

> 你的 `Employee` 类需要定义它自己的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？实现你认为 `Employee` 需要的拷贝控制成员。

可以显式的阻止拷贝

```cpp
#include <iostream>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(const string &name);
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};
```



### 练习 13.20

> 解释当我们拷贝、赋值或销毁 `TextQuery` 和 `QueryResult` 类对象时会发生什么？

成员被复制



### 练习 13.21

> 你认为 `TextQuery` 和 `QueryResult` 类需要定义它们自己版本的拷贝控制成员吗？如果需要，为什么？实现你认为这两个类需要的拷贝控制操作。

合成的版本满足所有的需求，因此不需要自定义拷贝控制成员。



### 练习 13.22

> 假定我们希望 `HasPtr` 的行为像一个值。即，对于对象所指向的 `string` 成员，每个对象都有一份自己的拷贝。我们将在下一节介绍拷贝控制成员的定义。但是，你已经学习了定义这些成员所需的所有知识。在继续学习下一节之前，为 `HasPtr` 编写拷贝构造函数和拷贝赋值运算符。

```cpp
#include <iostream>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &hp)
    {
        auto new_p = new string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }

private:
    string *ps;
    int i;
};
```



### 练习 13.23

> 比较上一节练习中你编写的拷贝控制成员和这一节中的代码。确定你理解了你的代码和我们的代码之间的差异。



### 练习 13.24

> 如果本节的 `HasPtr` 版本未定义析构函数，将会发生什么？如果未定义拷贝构造函数，将会发生什么？

- 如果没有定义析构函数：会导致类中动态分配的内存无法被释放，造成内存泄漏。
- 如果没有定义拷贝构造函数：