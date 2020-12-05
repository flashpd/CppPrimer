### 练习 15.1

> 什么是虚成员？

对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数



### 练习 15.2

> `protected` 访问说明符与 `private` 有何区别？

- `protected`：基类、派生类、友元可以访问
- `private`：只有基类本身和友元可以访问



### 练习 15.3

> 定义你自己的 `Quote` 类和 `print_total` 函数。

```cpp
// ex15_03.h
#include <iostream>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price)
        : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default; // 对析构函数进行动态绑定

private:
    string bookNo; // 书籍的ISBN编号
protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};
```

```cpp
// ex15_03.cpp
#include <iostream>
#include "ex15_03.h"
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    // 根据传入的item形参的对象类型调用Quote::net_price
    // 或者Bulk::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n
       << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote *quote1 = new Quote("C++", 100.0);
    print_total(cout, *quote1, 100);
    return 0;
}
```



### 练习 15.4

> 下面哪条声明语句是不正确的？请解释原因。
>
> ```cpp
> class Base { ... };
> (a) class Derived : public Derived { ... };
> (b) class Derived : private Base { ... };
> (c) class Derived : public Base;
> ```

- (a)不正确，类不能派生自身
- (b)不正确，这是定义不是声明
- (c)不正确，派生列表不能出现在这



### 练习 15.5

> 定义你自己的 `Bulk_quote` 类。

```cpp
class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &b, double p, size_t q, double disc)
        : Quote(b, p), min_qty(q), discount(disc) {}

    double net_price(size_t cnt) const override;

private:
    size_t min_qty = 0;    // 享受优惠的最低购入量
    double discount = 0.0; // 优惠
};
```



### 练习 15.6

> 将 `Quote` 和 `Bulk_quote` 的对象传给15.2.1节练习中的 `print_total` 函数，检查该函数是否正确。

见下一题

### 练习 15.7

> 定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出的部分将以原价销售。

直接在15.3的头文件里进行添加

```cpp
// ex15_3.h
#include <iostream>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price)
        : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default; // 对析构函数进行动态绑定

private:
    string bookNo; // 书籍的ISBN编号
protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &b, double p, size_t q, double disc)
        : Quote(b, p), min_qty(q), discount(disc) {}

    double net_price(size_t cnt) const override;

private:
    size_t min_qty = 0;    // 享受优惠的最低购入量
    double discount = 0.0; // 优惠
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
```

```cpp
// ex15_6.cpp
#include <iostream>
#include "ex15_03.h"
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    // 根据传入的item形参的对象类型调用Quote::net_price
    // 或者Bulk::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n
       << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote *quote = new Quote("C++", 100.0);
    print_total(cout, *quote, 100);

    Quote *bulk_quote = new Bulk_quote("C", 120, 10, 0.1);
    print_total(cout, *bulk_quote, 9);  // 120 * 9
    print_total(cout, *bulk_quote, 10); // 120 * 10 * 0.9
    print_total(cout, *bulk_quote, 11); // 120 * 11 * 0.9

    return 0;
}
```



### 练习 15.8

> 给出静态类型和动态类型的定义。



### 练习 15.9

> 在什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。



### 练习 15.10

> 回忆我们在8.1节进行的讨论，解释第284页中将 `ifstream` 传递给 `Sales_data` 的`read` 函数的程序是如何工作的。

`ifsteam`是`istream`的派生基类，因此`read`函数能正常工作。



### 练习 15.11

> 为你的 `Quote` 类体系添加一个名为 `debug` 的虚函数，令其分别显示每个类的数据成员。

```cpp
void Quote::debug() const
{
    cout << "data members of this class:\n"
         << "bookNo= " << this->bookNo << " "
         << "price= " << this->price << " ";
}
```



### 练习 15.12

> 有必要将一个成员函数同时声明成 `override` 和 `final` 吗？为什么？

有必要。`override`的含义是重写基类中相同名称的虚函数，`final`是阻止它的派生类重写当前虚函数。



### 练习 15.13

> 给定下面的类，解释每个 `print` 函数的机理：
>
> ```cpp
> class base {
> public:
> 	string name() { return basename;}
> 	virtual void print(ostream &os) { os << basename; }
> private:
> 	string basename;
> };
> class derived : public base {
> public:
> 	void print(ostream &os) { print(os); os << " " << i; }
> private:
> 	int i;
> };
> ```

改成如下，完整测试代码见下文

```
    derived(string bn, int i) : base(bn), i(i) {}
    void print(ostream &os) override
    {
        base::print(os);
        os << " " << i;
    }
```

```cpp
#include <iostream>
using namespace std;

class base
{
public:
    base(string bn) : basename(bn) {}
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }

private:
    string basename;
};
class derived : public base
{
public:
    derived(string bn, int i) : base(bn), i(i) {}
    void print(ostream &os) override
    {
        base::print(os);
        os << " " << i;
    }

private:
    int i;
};

int main()
{
    base *b1 = new base("C++");
    cout << b1->name() << endl;
    b1->print(cout);
    cout << endl;

    derived *d1 = new derived("C", 100);
    d1->print(cout);
    cout << endl;
    cout << d1->name();
    cout << endl;
    
    return 0;
}
```



### 练习 15.14

> 给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数：
>
> ```cpp
> base bobj; 		base *bp1 = &bobj; 	base &br1 = bobj;
> derived dobj; 	base *bp2 = &dobj; 	base &br2 = dobj;
> (a) bobj.print();	(b)dobj.print();	(c)bp1->name();
> (d)bp2->name();		(e)br1.print();		(f)br2.print();
> ```

- (a)(b)(c)(d)是编译时
- (e)是运行时，`base::print()`
- (f)是运行时，`derived::print()`



### 练习 15.15

> 定义你自己的 `Disc_quote` 和 `Bulk_quote`。

```cpp
#include "Quote.h"

/* Disc_quote的类用来支持不同的折扣策略 */
class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc) {}

    virtual double net_price(size_t cnt) const = 0;

protected:
    size_t quantity = 0;   // 折扣适用的购买量
    double discount = 0.0; // 表示折扣的小数值
};
```

```cpp
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc)
        : Disc_quote(book, price, qty, disc) {}

    double net_price(size_t cnt) const override;
    void debug() const override;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
```



### 练习 15.6

> 改写你在15.2.2节练习中编写的数量受限的折扣策略，令其继承 `Disc_quote`。

```cpp
#include "Disc_quote.h"

class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string book, double price, size_t max, double disc)
        : Disc_quote(book, price, max, disc) {}
    double net_price(size_t cnt) const override;
    void debug() const override;
};

double Limit_quote::net_price(size_t cnt) const
{
    return cnt * price * (cnt > quantity ? 1 - discount : 1);
}
```



### 练习 15.17

> 尝试定义一个 `Disc_quote` 的对象，看看编译器给出的错误信息是什么？



### 练习 15.18

> 假设给定了第543页和第544页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：
>
> ```cpp
> Base *p = &d1; // d1 的类型是 Pub_Derv
> p = &d2;       // d2 的类型是 Priv_Derv
> p = &d3;       // d3 的类型是 Prot_Derv
> p = &dd1;      // dd1 的类型是 Derived_from_Public
> p = &dd2;      // dd2 的类型是 Derived_from_Private
> p = &dd3;      // dd3 的类型是 Derived_from_Protected
> ```

只有派生类使用`public`继承时，用户代码才可以使用从派生类到基类的转换

```cpp
Base *p = &d1; // 合法
p = &d2;       // 不合法
p = &d3;       // 不合法
p = &dd1;      // 合法
p = &dd2;      // 不合法
p = &dd3;      // 不合法
```



### 练习 15.19

> 假设543页和544页的每个类都有如下形式的成员函数：
>
> ```cpp
> void memfcn(Base &b) { b = *this; }
> ```



### 练习 15.20

> 编写代码检验你对前面两题的回答是否正确。



### 练习 15.21

> 从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应的一组类型组织成一个继承体系：
>
> ```c
> (a) 图形文件格式（如gif、tiff、jpeg、bmp）
> (b) 图形基元（如方格、圆、球、圆锥）
> (c) C++语言中的类型（如类、函数、成员函数）
> ```

```cpp
#include <iostream>
using namespace std;

class Shape
{
public:
    typedef std::pair<double, double> Coordinate;

    Shape() = default;
    Shape(const std::string &n) : name(n) {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() = default;

private:
    std::string name;
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(const std::string &n,
              const Coordinate &a,
              const Coordinate &b,
              const Coordinate &c,
              const Coordinate &d) : Shape(n), a(a), b(b), c(c), d(d) {}

    ~Rectangle() = default;

protected:
    Coordinate a;
    Coordinate b;
    Coordinate c;
    Coordinate d;
};

class Square : public Rectangle
{
public:
    Square() = default;
    Square(const std::string &n,
           const Coordinate &a,
           const Coordinate &b,
           const Coordinate &c,
           const Coordinate &d) : Rectangle(n, a, b, c, d) {}

    ~Square() = default;
};

int main()
{
    return 0;
}
```



### 练习 15.22

> 对于你在上一题中选择的类，为其添加函数的虚函数及公有成员和受保护的成员。



### 练习 15.23

> 假设第550页的 `D1` 类需要覆盖它继承而来的 `fcn` 函数，你应该如何对其进行修改？如果你修改之后 `fcn` 匹配了 `Base` 中的定义，则该节的那些调用语句将如何解析？



### 练习 15.24

> 哪种类需要虚析构函数？虚析构函数必须执行什么样的操作？

基类通常都应该定义一个虚析构函数，即使该函数不执行任何实际操作也是如此。（参考15.2节）







