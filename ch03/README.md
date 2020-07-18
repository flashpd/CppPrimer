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