## Exercise 6.1

> 实参和形参的区别是什么？

实参：函数调用时提供的值，用于初始化函数的形参。（书本P225）

形参：在函数的形参列表中声明的局部变量。用实参初始化形参。（书本P226）



## Exercise 6.2

> 修改错误

```c++
(a) int f() {	// int -> string
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }  // f2 -> void f2
(c) int calc(int v1, int v1) { /* ... */ }  // 改掉一个v1的名字 如 (int v1, int v2)
(d) double square (double x)  return x * x;   // 缺少大括号
```



## Exercise 6.3



## Exercise 6.4



## Exercise 6.5



## Exercise 6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。

形参：在函数的参数列表中定义的局部变量

局部变量：形参和函数体内部定义的变量统称为局部变量。（书本P184）

局部静态变量：在程序的执行路径第一次经过对象定义的语句时初始化，并且直到程序终止才被销毁，在此期间即使对象所在的函数结束执行也不会对它有影响。（书本P185）



## Exercise 6.7



## Exercise 6.8



## Exercise 6.9



## Exercise 6.10



## Exercise 6.11



## Exercise 6.12



## Exercise 6.13

> 说明`void f(T)`和`void f(&T)`的区别

前者的T是复制进f函数中，后者是将T作为别名引用到函数f中不产生复制。



## Exercise 6.14

> 形参是引用的例子

```c++
void reset(int &i)
{
    i = 0;
}
```

> 形参不能是引用类型的例子

```c++
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```



## Exercise 6.15

> find_char函数中的三个形参，为什么s是常量引用，occurs是普通引用，为什么c不是引用？

s是原始字符串使用引用可以避免复制，而且不能被修改，所以是常量引用

occurs是统计次数，所以是普通引用

c可能是临时变量，不需要是引用



## Exercise 6.16

```c++
bool is_empty(string& s) { return s.empty(); }
```

改善后↓

```
bool is_empty(const string& s) { return s.empty(); }
```



## Exercise 6.17



## Exercise 6.18

```c++
bool compare(matrix &m1, matrix &m2);
```

```c++
void change_val(int i, vector<int>::iterator v1);
```



## Exercise 6.19



## Exercise 6.20

当形参不需要被修改的时候采用常量引用。



## Exercise 6.21



## Exercise 6.22

> 交换两个int型指针。



## Exercise 6.23

（书本上有很多）



## Exercise 6.24

> 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。

```c++
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

传入一个含有10个元素的整型数组，然后逐个打印，传入的数组大小可以不为10。

本地运行没有问题，如果需要进行数组引用的话，进行如下修改

```c++
void print(const int （&ia）[10])
```



## Exercise 6.25



## Exercise 6.26

参见Exercise 6.25



## Exercise 6.27



## Exercise 6.28

const string &



## Exercise 6.29



## Exercise 6.30



## Exercise 6.31



## Exercise 6.32

合法



## Exercise 6.33



## Exercise 6.34

如果传入参数为正，则正常进行，如果传入参数为符数则无法正常终止。



## Exercise 6.35

> 在调用factorial函数时，为什么我们传入的值是val-1而非val--？

如果是前者，那么递归调用的值是val-1

如果是后者，那么递归调用的是val



第六章后面先不写了，留个坑等第二遍





