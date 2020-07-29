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



## Exercise 5.12



## Exercise 5.13

> 下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。

```c++
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

↓

```c++
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;	// 没有加上break
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        default: iouCnt++; break;
    }
(b) unsigned index = some_value();	// 跨过case标签的变量应该定义在外面
	int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {	// case格式不正确
        case 1: case 3: case 5: case 7: case 9:
            oddCnt++;	// 变量名错误
            break;
        case 2: case 4: case 6: case 8: case 10:
            evenCnt++;	// 变量名错误
            break;
    }
(d) const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {	// case标签只能是整型常量
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```



## Exercise 5.14

[大佬代码](https://github.com/Mooophy/Cpp-Primer/blob/master/ch05/ex5_14.cpp)



## Exercise 5.15

> 说明下列循环的含义并改正其中的错误。

```c++
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
```

↓

```c++
(a) int ix;	// ix在for循环外面也要用，所以要定义到外面
	for (ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;	// for循环写的不对
    for (; ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix) { /*...*/ }	// sz如果也一起增长，for循环无法结束 
```



## Exercise 5.16



## Exercise 5.17



## Exercise 5.18

> 说明下列循环的含义并改正其中的错误。

```c++
(a) do 
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);

(b) do {
        // . . .
    } while (int ival = get_response());

(c) do {
        int ival = get_response();
    } while (ival);
```

↓

```c++
(a) do{	// 需要加上大括号
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while (cin);

(b) int ival;
	do {
        // . . .
    } while (ival = get_response());

(c) int ival;
	do {
        ival = get_response();
    } while (ival);
```



## Exercise 5.19



## Exercise 5.20



## Exercise 5.21



## Exercise 5.22



## Exercise 5.23



## Exercise 5.24



## Exercise 5.25

