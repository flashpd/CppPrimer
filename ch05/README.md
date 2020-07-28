## Exercise 5.1

> 什么是空语句？什么时候会用到空语句？

`;`就是空语句，当程序在某个地方，语法上需要一条语句但是逻辑上不需要，此时应该使用空语句。(P154）



## Exercise 5.2

> 什么是块？什么时候会用到块？

复合语句也被成为块，如果在程序的某个地方，语法上需要一条语句 ，但是逻辑上需要多条语句，则应该使用复合语句。



## Exercise 5.3

> 使用逗号运算符（参见4.10节，第140页）重写1.41节（第10页）的while循环使其不再需要块，观察改写之后的代码的可读性提高了还是降低了。

```c++
while (val <= 10)
    sum += val, ++val;
```

可读性降低了



## Exercise 5.4

> 说明下列例子的含义，如果存在问题，试着修改它。

```c++
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ } 
	if (!status) { /* . . . */ }
```

(a)句语法错误，应该改为↓

```c++
string::iterator iter = s.begin();
while (iter != s.end()) { /* . . . */ }
```

(b)句语法错误，应该改为↓

```c++
bool status;
while (status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }
```



## Exercise 5.5



## Exercise 5.6



## Exercise 5.7

> 改正下列代码段中的错误。

```c++
(a) if (ival1 != ival2) 
    	ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) 
    	minval = ival;
    	occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```

↓

```c++
(a) if (ival1 != ival2) ival1 = ival2;	// 第一行缺少分号  
(b) if (ival < minval)	// 缺少分号  
    {
    	minval = ival;
    	occurs = 1;
    }
(c) int ival;	// 把ival定义到外面
	if (ival = get_value())
(d) if (ival == 0)	// '=' 改成 '=='
```



## Exercise 5.8

> 什么是“悬垂else”？C++语言是如何处理else子句的？

没有进行匹配的else被称为悬垂else

在C++中，else与离它最近的尚未匹配的if匹配



## Exercise 5.9



## Exercise 5.10



## Exercise 5.11



