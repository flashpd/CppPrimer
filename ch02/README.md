## Exercise 2.1

> `int`、`long` 、`long long`、`short`的区别是什么？无符号类型和带符号类型的区别是什么？`float`和`double`的区别是什么？

1、四个表示的范围不一样；

2、无符号类型仅能表示大于0的值，带符号类型能表示正数、复数或0；

3、通常`float`以1个字（32比特）来表示，`double`以2个字（64比特）来表示。



## Exercise 2.2

> 对于利率、本金和付款分别应该选择何种数据类型？

都应该选用`float`或`double`



## Exercise 2.3

> 读程序写结果

```c++
unsigned u = 10, u2 = 42;	
std::cout << u2 - u << std::endl;	//32
std::cout << u - u2 << std::endl;	//4294967264
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;	//32
std::cout << i - i2 << std::endl;	//-32
std::cout << i - u << std::endl;	//0
std::cout << u - i << std::endl;	//0
```



## Exercise 2.4

> 编写程序检查你的估计是否正确

上述结果都对



## Exercise 2.5

- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): char字符型，宽字符型，字符串型，宽字符字符串型

(b): 整型，无符号整型，长整型，无符号长整型，八进制，十六进制

(c): double，float，long double

(d): 整型，无符号整型，double，double



## Exercise 2.6

> 下面两组定义是否有区别，如果有，请叙述之：

```c++
int month = 9, day = 7;
int month = 09, day = 07;
```

第一行是十进制的9和7，第二行是八进制，八进制中没有09这个数字



## Exercise 2.7

> 下述字面值表示何种含义？他们各自的数据类型是什么？

- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?（后面跟着一个换行）"string"

(b): 31.4 "double"

(c): error: unable to find numeric literal operator 'operator""f'

(d): 3.14 "long double"



## Exercise 2.8

> 请利用转义序列编写一段程序，要求先输出2M，然后转到新一行。修改程序使其先输出2，然后输出制表符，再输出M，最后转到新一行。

```c++
#include <iostream>

int main()
{
    std::cout << "2\115\012";
    std::cout << "2\t\115\012";
    return 0;
}
```



## Exercise 2.9

> 解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。

- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int i = 3.14;

(a): 非法，

```c++
int input_value;
std::cin >> input_value;
```

(b): 非法，`double i = { 3.14};`

(c): 非法

```c++
double wage = 9999.99; 
double salary = wage;
```

(d): 非法，`double i = 3.14;`



## Exercise 2.10

> 下列变量的初值分别是什么？

```c++
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_int;
}
```

global_str定义于函数外，初始值为空串，global_int定义于函数外，初始值为0，local_int和local_int都是定义于函数内，所以初始值未知。详情参考本书40页。



## Exercise 2.11

> 指出下面的语句是声明还说定义：

- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

(a): 定义，(b): 定义，(c): 声明。



## Exercise 2.12

> 请指出下面的名字中哪些是非法的？

- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

(b)和(e)合法，其余非法。



## Exercise 2.13

> 下面程序中j的值是多少

```c++
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

j的值是100



## Exercise 2.14

> 下面的程序合法吗？如果合法，它将输出什么？

```c++
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```

100 45

PS：不推荐i的命名方式，见本书45页



## Exercise 2.15

> 下面哪个定义是不合法的？为什么？

- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

(a): 合法，(b): 不合法，引用初始化必须是对象，(c): 合法，(d): 不合法，引用没有初始化



## Exercise 2.16

> 哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行力什么样的操作？

`int i = 0, &r1 = i; double d = 0, &r2 = d;`

- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;

(a): 合法，输出 `3.14159`

(b): 合法，输出`0`

(c): 合法，输出`0`

(d): 合法，输出`0`



## Exercise 2.17

> 执行下面的代码段将输出什么结果？

```c++
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

输出`10 10`



## Exercise 2.18

>编写代码分别更改指针的值以及指针指向对象的值。

```
#include <iostream>

int main()
{
    int a = 10;
    int *b = &a;
    int *c = b;
    int d = 20;
    std::cout << "a " << a << " | *b " << *b << " | *c " << *c << std::endl;

    *b = 11;
    std::cout << "a " << a << " | *b " << *b << " | *c " << *c << std::endl;

    *c = d;
    std::cout << "a " << a << " | *b " << *b << " | *c " << *c << std::endl;
    return 0;
}
```



## Exercise 2.19

> 请说明指针和引用的区别。

①引用并非对象，它只是为一个已经存在的对象所起的另外一个名字。指针本身就是一个对象，允许对指针赋值和拷贝而且在指针生命周期内它可以先后指向几个不同的对象。

②定义引用的时候，程序把引用和它的初始值绑定在一起，而不是将初始值拷贝给引用，一旦初始化完成，引用将和它的初始值对象一直绑定在一起，因为无法令引用重新绑定到另外一个对象，因此引用必须初始化。指针无须在定义时赋初值，和其他内置类型一样，在块作用域内定义指针如果没有初始化，也将拥有一个不确定的值。



## Exercise 2.20

> 请叙述下面这段代码的作用。

```c++
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```

用指针`p1`指向`i`，然后计算42 * 42，最后`*p1`和`i`的值都为1764



## Exercise 2.21

> 请解释下列定义。在这些定义中有非法的吗？如果有，为什么？

`int i = 0;`

- (a) double* dp = &i;
- (b) int *ip = i;
- (c) int *p = &i;

(a): 不合法，指针类型不匹配，应该是`int *`

(b): 不合法，`i`前没有引用符

(c): 合法



## Exercise 2.22

> 假设p是一个int型指针，请说明下述代码的含义。

```c++
if (p) // ...
if (*p) // ...
```

第一行：判断p是否为空

第二行：判断指针p指向的值是否为空



## Exercise 2.23

> 给定指针p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能



## Exercise 2.24

> 在下面这段代码中为什么p合法而lp非法？

```c++
int i = 42;
void *p = &i;
long *lp = &i;
```

`void *`指针是一种特殊的指针类型，可用于存放任意对象的地址。`long *`属于类型不匹配。



## Exercise 2.25

> 说明下列变量的类型和值。

- (a) int* ip, i, &r = i;
- (b) int i, *ip = 0;
- (c) int* ip, ip2;

(a): `ip`是int型指针，`i`是int型，`r`是`i`的引用。

(b): `i`是int型，`ip`是int型空指针。

(c): `ip`是指针，`ip2`是int型。



## Exercise 2.26

> 下面哪些句子是合法的？如果有不合法的句子，请说明为什么？

- (a) const int buf;
- (b) int cnt = 0;
- (c) const int sz = cnt;
- (d) ++cnt; ++sz;

(b)，(c)，(d)是合法的，(a)中buf应该初始化，(d)中sz被const修饰，不能被修改。



## Exercise 2.27

> 下面的哪些初始化是合法的？请说明原因。

```c++
int i = -1, &r = 0;         // 不合法，r是引用，应该引用的是一个对象。
int *const p2 = &i2;        // 合法。
const int i = -1, &r = 0;   // 合法。
const int *const p3 = &i2;  // 合法。
const int *p1 = &i2;        // 合法。
const int &const r2;        // 不合法，r2是个引用，不能加const，应该去掉&后的const并初始化
const int i2 = i, &r = i;   // 合法。
```



## Exercise 2.28

> 说明下面的这些定义是什么意思，挑出其中不合法的。

```c++
int i, *const cp;       // 不合法，cp应该被初始化。
int *p1, *const p2;     // 不合法，p2应该被初始化。
const int ic, &r = ic;  // 不合法，ic没有初始化。
const int *const p3;    // 不合法，p3应该被初始化。
const int *p;           // 合法。
```



## Exercise 2.29

> 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。

```c++
i = ic;     // 合法。
p1 = p3;    // 不合法，p3没有被初始化。
p1 = &ic;   // 不合法，ic被const修饰
p3 = &ic;   // 不合法，
p2 = p1;    // 不合法，p2是指针常量，p2自身的值不能被修改。
ic = *p3;   // 不合法，ic是常量
```



## Exercise 2.30

> 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const。

```c++
const int v2 = 0; int v1 = v2;	//v2是顶层const
int *p1 = &v1, &r1 = v1;
//p2是底层const，p3既是顶层const也是底层const，r2是底层const
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```



## Exercise 2.31

> 假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。

```c++
r1 = v2; // 合法，r2是顶层const
p1 = p2; // 不合法，p2是底层const，p1不是
p2 = p1; // 合法，p1是int型指针，p2是底层const
p1 = p3; // 不合法，p3包含底层const
p2 = p3; // 合法，两者都是底层const
```



## Exercise 2.32

> 下面的代码是否合法？如果非法，请设法将其修改正确。

```c++
int null = 0， *p = null；
```

修改为：

```c++
int null = 0， *p = &null；
```

或者

```c++
int null = 0， *p = nullptr；
```



## Exercise 2.33

> 利用本节定义的变量，判断下列语句的运行结果。

```c++
a=42; // 将a的值置为42
b=42; // 将b的值置为42
c=42; // 将c的值置为42
d=42; // 非法，d本身是个int型指针
e=42; // 非法，e是常量指针
g=42; // 非法，g是常量引用，无法被修改
```



## Exercise 2.34

> 基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。



## Exercise 2.35

> 判断下列定义推断出的类型是什么，然后编写程序进行验证。

```c++
    const int i = 42;	//
    auto j = i;			//j是int型
    const auto &k = i;	//k是int型常量引用
    auto *p = &i;		//p是int型常量指针
    const auto j2 = i, &k2 = i;	//j2是常量整型，k2是int型常量引用
```



## Exercise 2.36

> 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。

```c++
int a = 3, b = 4;
decltype(a) c = a;		// c是int型，值为3
decltype((b)) d = a;	// d是int型引用，值为3
++c;					// 此时c的值为4
++d;					// 此时d的值为4
```



## Exercise 2.37

> 请写出下面的代码中每一个变量的类型和值。

```c++
int a = 3, b = 4;		
decltype(a) c = a;		// c是int型，值为3
decltype(a = b) d = a;	// d是int型引用，值为3
```



## Exercise 2.38

> 说明由`decltype`指定类型和由`auto`指定类型有何区别。请举出一个例子，`decltype`指定的类型与`auto`指定的类型一样；再举一个例子，`decltype`指定的类型和`auto`指定的类型不一样。

可以看看StackOverflow的大佬回答：[点击这里](https://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun)



## Exercise 2.39

> 编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息，以后可能会有用。

```c++
struct Foo { /* empty  */ } // Note: no semicolon
int main()
{
    return 0;
}
```

直接运行会因为第一行没有分号而报错。



后续三道题先不更了……

## Exercise 2.40



## Exercise 2.41



## Exercise 2.42

