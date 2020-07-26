## Exercise 4.1

> 表达式`5 + 10 * 20 / 2`的求值结果是多少？

105



## Exercise 4.2

> 根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。

```c++
* vec.begin()	//-->  *(vec.begin())
* vec.begin() + 1 	//--> (*(vec.begin())) + 1
```



## Exercise 4.3

> C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行权衡，你认为这可以接受吗？请说出你的理由。

不能接受，这样做的话，会引起难以预测的错误。



## Exercise 4.4

> 在下面的表达式中添加括号，说明其求值的过程及最终结果。编写程序编译该（不加括号的）表达式并输出其结果验证之前的推断。

```c++
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

//--> ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
```

91



## Exercise 4.5

> 写出下列表达式的求值结果。

```c++
(a) -30 * 3 + 21 / 5  // -86
(b) -30 + 3 * 21 / 5  // -18
(c) 30 / 3 * 21 % 5   // 0
(d) -30 / 3 * 21 % 4  // -2
```



## Exercise 4.6

> 写出一条表达式用于确定一个整数是奇数还是偶数。

```c++
a % 2
```

```c++
a & 0x1
```



## Exercise 4.7

> 溢出是何含义？写出三条将导致溢出的表达式。

溢出就是值的大小超出了机器所能表示的范围

```c++
int a1 = 2147483647;
cout << a1 << " ";	// 2147483647
cout << a1 + 1 << endl;	// -2147483648

unsigned int a2 = 4294967295;
cout << a2 << " ";	// 4294967295
cout << a2 + 1 << endl;	// 0

short a3 = 65535;
cout << a3 << " ";	// -1
cout << a3 + 1 << endl;	// 0
```



## Exercise 4.8

> 说明在逻辑与、逻辑或及相等性运算符中运算对象求值的顺序。

逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象无法确定表达式的结果时才会计算右侧运算对象的值。这种策略称为短路求值。（书本P126）



## Exercise 4.9

> 解释在下面的if语句中条件部分的判断过程。

```c++
const char *cp = "Hello World";
if (cp && *cp)
```

cp是一个指针，不为空，所以是true

*cp指向`H`，也不为空，也是true



## Exercise 4.10

> 为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止。

```c++
while(cin >> a && a != 42)
```



## Exercise 4.11

> 书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b，b大于c，c大于d。

```c++
a > b && b > c && c > d
```



## Exercise 4.12

> 假设i、j和k是三个整数，说明表达式`i != j < k`的含义。

先判断`j < k`是否为真，为真则返回1，为假则返回0，记这个返回值是temp，然后再判断`i != temp `是否正确。

功能等于`i != (j < k)`



## Exercise 4.13

> 在下述语句中，当赋值完成后i和d的值分别是多少？

```c++
int i;   double d;
(a) d = i = 3.5;	// d = 3.0 i = 3
(b) i = d = 3.5;	// i = 3 d = 3.5
```



## Exercise 4.14

> 执行下述if语句后将发生什么情况？

```c++
if (42 = i)   // 编译报错
if (i = 42)   // 返回true
```



## Exercise 4.15

> 下面的赋值是非法的，为什么？应该如何修改？

```c++
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

pi是指针，应该改为↓

```c++
dval = ival = 0;
pi = 0;
```



## Exercise 4.16

>尽管下面的语句合法，但它们执行的行为可能和预期并不一样，为什么？应该如何修改？

```c++
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```

↓

```c++
(a) if ((p = getPtr()) != 0)
(b) if (i == 1024)
```



## Exercise 4.17

> 说明前置递增运算符和后置递增运算符的区别。

++i是先进行+1操作，然后再进行其他，i++是先以当前i值进行操作，然后执行i+1



## Exercise 4.18

> 如果第132页那个输出vector对象元素的while循环使用前置递增运算符，你将得到什么结果。

会从2开始，一直打印



## Exercise 4.19

> 假设ptr的类型是指向int的指针、vec的类型是vector<int>、ival的类型是int，说明下面的表达式是何含义？如果表达式不正确，为什么？应该如何修改？

```c++
(a) ptr != 0 && *ptr++	// 先判断ptr是否为空指针，然后查看ptr指向的值
(b) ival++ && ival	// 简称ival和ival+1是否为空
(c) vec[ival++] <= vec[ival]	// 错误
```

↓

```c++
(c) vec[ival] <= vec[ival++]
```



## Exercise 4.20

> 假设iter的类型是`vector<string>::iterator`，说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？

```c++
(a) *iter++;	// 合法 iter向后移动
(b) (*iter)++;	// 不合法 *iter是string类型不能执行+1操作
(c) *iter.empty()	// 不合法 解引用运算符的优先级低于点运算符
(d) iter->empty();	// 判断iter是否为空
(e) ++*iter;	// 不合法 *iter是string类型
(f) iter++->empty();	// 先判断iter是否为空 然后向后移动
```



## Exercise 4.21



## Exercise 4.22



## Exercise 4.23

> 因为运算符优先级的问题，下面这条表达式无法通过编译。根据4.12节中的表（第147页）指出它的问题在哪里？应该如何修改？

```c++
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

↓

```c++
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```



## Exercise 4.24

> 本节的示例程序将成绩划分high pass、pass和fail三种，它的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合律，求值过程将是怎样的？

```c++
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

会变成先判断是否为输出high pass，然后再输出fail

```c++
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```



## Exercise 4.25

> 如果一台机器上int占32位、char占8位，用的是Latin-1字符集，其中字符'q'的二进制形式是01110001，那么表达式~'q' << 6的值是什么？

-7296



## Exercise 4.26

> 在本节关于测验成绩的例子中，如果使用unsigned int作为quiz1的类型会发生什么情况？



## Exercise 4.27

> 下列表达式的结果是什么？

```c++
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2	// 3
(b) ul1 | ul2	// 7
(c) ul1 && ul2	// true
(d) ul1 || ul2	// true
```



## Exercise 4.28



## Exercise 4.29

> 推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如果不一样，为什么？

```c++
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

输出↓，和我预期一样

```
10
1
```



## Exercise 4.30

> 根据4.12节中的表（第147页），在下述表达式的适当位置加上括号，使得加上括号之后表达式的含义与原来的含义相同。

```c++
(a) sizeof x + y      
(b) sizeof p->mem[i]  
(c) sizeof a < b      
(d) sizeof f()        
```



```c++
(a) (sizeof x) + y	// sizeof的优先级比'+'高      
(b) sizeof (p->mem[i])	//
(c) sizeof (a) < b		
(d) sizeof f()    
```



## Exercise 4.31



## Exercise 4.32

> 解释下面这个循环的含义。

```c++
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

ptr和ix不断的递增，直到ix等于5



## Exercise 4.33

> 根据4.12节中的表（第147页）说明下面这条表达式的含义。

```c++
someValue ? ++x, ++y : --x, --y
```

如果somevalue为真，则执行++x和++y，然后执行--y

如果somevalue为假，则执行--x，然后执行--y



## Exercise 4.34

> 根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换：

```c++
if (fval)	// fval转成bool型
dval = fval + ival;	// ival先转换成float型 然后转换成double型
dval + ival * cval;	// cval先转换成int型 然后转换成double型
```



## Exercise 4.35

> 假设有如下的定义。

```c++
char cval; int ival; unsigned int ui; 
float fval; double dval;
```

> 请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。

```c++
cval = 'a' + 3;	// 'a' + 3转为char类型
fval = ui - ival * 1.0;	// ival转换成double型 最后转为float型
dval = ui * fval;	// ui转为float型 最后转为double型
cval = ival + fval + dval;	// ival转float型 然后转为float型 最后转换为char类型
```



## Exercise 4.36

> 假设i是int类型，d是double类型，书写表达式i *= d使其执行整数类型的乘法而非浮点类型的乘法。



## Exercise 4.37



## Exercise 4.38



