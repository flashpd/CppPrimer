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



















