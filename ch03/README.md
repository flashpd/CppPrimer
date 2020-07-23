## Exercise 3.2



## Exercise 3.3

> 请说明`string`类的输入运算符和`getline`函数分别是如何处理空白字符的。

`is >> s`从is中读取字符赋给s，字符串以空白分隔。

`getline(is, s)`从is中读取一行赋给s，字符串中间的空白字符不另作处理

`getline(is, s, delim)`从is中读取一行赋给s，以delim为分割。



## Exercise 3.4

> 编写程序，读入两个字符串，相等则输出，否则输出较大的字符串。改写，比较两个字符串的长度是否相等，相等则输出，否则，输出长度较大的字符串。



## Exercise 3.5



## Exercise 3.6



## Exercise 3.7



## Exercise 3.8



## Exercise 3.9

> 下面的程序有何作用？它合法吗？如果不合法，为什么？

```c++
string s;
cout << s[0] << endl;
```

作用：输入s的首个字符，但是不合法，因为s是空字符串



## Exercise 3.10



## Exercise 3.11

> 下面的范围for语句合法？如果合法，c的类型是什么

```c++
const string s = "Keep out!";
for (auto &c : s) { /*...*/ }
```

如果大括号里面是cout则合法，大括号里面修改c的值则不合法。



## Exercise 3.12

> 下列vector对象的定义是否正确？

```c++
vector<vector<int>> ivec;         // 合法.
vector<string> svec = ivec;       // 不合法 svec和ivec的类型不一样
vector<string> svec(10, "null");  // 合法，svec有10个"null"的元素
```



## Exercise 3.13

> 下列的vector对象各包含多少元素？这些元素的值分别是多少？

```c++
(a)vector<int> v1;         // 空.
(b)vector<int> v2(10);     // 10个元素，值为0
(c)vector<int> v3(10, 42); // 10个元素，值为42
(d)vector<int> v4{ 10 };     // 1个元素，值为10
(e)vector<int> v5{ 10, 42 }; // 2个元素，值为10、42
(f)vector<string> v6{ 10 };  // 10个元素，值为"null"
(g)vector<string> v7{ 10, "hi" };  // 10个元素，值为"hi"
```



## Exercise 3.14



## Exercise 3.15



## Exercise 3.16



## Exercise 3.17

> 从cin中读入一组词并把它们存入一个vector对象，然后将所有的词改成大写。输出改变后的结果，每个词占一行。



## Exercise 3.18

> 下面的程序是否合法？如果不合法，你准备如何修改？

```c++
vector<int> ivec;
ivec[0] = 42;
```

不合法，修改如下：

```c++
vector<int> ivec{42};
```



## Exercise 3.19

> 如果想定义一个含有10个元素的vector对象，所有元素值都是42，请列举三种不同的实现方法。哪种方法更好呢？为什么？

```c++
vector<int> v1(10, 42);
vector<int> v2(v1);
vector<int> v3{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
```

第一种更好一些，简单快捷



## Exercise 3.20



## Exercise 3.21



## Exercise 3.22



## Exercise 3.23



## Exercise 3.24



## Exercise 3.25



## Exercise 3.26

> 在100页的二分搜索程序中，为什么用的是`mid=beg+(end-beg)/2`，而非`mid=(beg+end)/2`;？

因为两个迭代器无法相加



## Exercise 3.27

> 假设txt_size是一个无参数的函数，它的返回值是int。请回答下列哪个定义是非法的？为什么？

```c++
unsigned buf_size = 1024;

int ia[buf_size];   // 不合法 buf_size不是常量表达式
int ia[4 * 7 - 14]; // 合法
int ia[txt_size()]; // 不合法 维度不是常量表达式
char st[11] = "fundamental";  // 不合法 没有空间存放空字符
```



## Exercise 3.28

> 下列数组中元素的值是什么？

```c++
string sa[10];      //空串
int ia[10];         //默认值是0

int main() 
{
    string sa2[10]; //全是空串
    int ia2[10];    //值不确定
}
```



## Exercise 3.29

> 相比于 vector来说，数组有哪些缺点，请列举一些。

1、大小固定

2、没有API

3、Bug prone



## Exercise 3.30

> 指出下面代码中的索引错误。

```c++
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```

第三行ix不能等于array_size



## Exercise 3.31



## Exercise 3.32



## Exercise 3.33

> 对于104页的程序来说，如果不初始化scores将发生什么？

scores内的值都没有定义。



## Exercise 3.34

> 假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？

```c++
p1 += p2 - p1;
```

程序功能：将p1移动p2-p1的偏移值，然后p1和p2指向同一个地址，测试代码如下。

```c++
int a[] = {1, 100, 1000};
int *p1 = &a[0];
int *p2 = &a[1];

p1 += p2 - p1;
cout << p1 << " " << p2 << endl;
```

在任何情况下都是合法的



## Exercise 3.35



## Exercise 3.36



## Exercise 3.37

> 下面程序是何含义，程序的输出结果是什么？

```c++
const char ca[5] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp)
{
    cout << *cp << endl;
    ++cp;
}
```

输出ca数组内的字符后，仍会输出一些未知字符，因为要遇到'\0'才能结束



## Exercise 3.38

> 在本节中我们提到，将两个指针相加不但是非法的，而且没什么意义。请问为什么两个指针相加没什么意义？

指针指向的是一个地址，两个指针相加得到的就是一个未知的地址，所以没有意义，在内存中，这个未知的地址可能指向一些危险的区域，所以是非法的（全凭个人理解）



## Exercise 3.39



## Exercise 3.40



## Exercise 3.41



## Exercise 3.42



## Exercise 3.43



