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

