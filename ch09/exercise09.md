### 练习 9.1

> 对于下面的程序任务，`vector`、`deque`和`list`哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
>
> (a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
>
> (b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
>
> (c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

(a) 选择`list`，因为需要频繁的插入操作

(b) 选择`deque`，因为需要在头尾进行插入删除操作

(c) 选择`vector`，不需要进行插入删除操作



### 练习 9.2

> 定义一个`list`对象，其元素类型是`int`的`deque`。

```cpp
list<deque<int>> myList;
```



### 练习 9.3

> 构成迭代器范围的迭代器有何限制？

- `begin`和`end`分别指向同一个容器中的元素或者是尾元素之后的位置。

- `end`不能指向`begin`之前的位置。



### 练习 9.4

> 编写函数，接受一对指向`vector<int>`的迭代器和一个`int`值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
    while (begin++ != end)
    {
        if (*begin == i)
            return true;
    }
    return false;
}
```



### 练习 9.5

> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```cpp
// auto可以换成vector<int>::const_iterator
auto find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
    while (begin != end)
    {
        if (*begin == i)
            return begin;
        begin++;
    }
    return end;
}
```



### 练习 9.6

> 下面的程序有何错误？你应该如何修改它？
>
> ```cpp
> list<int> lst1;
> list<int>::iterator iter1 = lst1.begin(),
> 					iter2 = lst1.end();
> while (iter1 < iter2) /* ... */
> ```

```cpp
while (iter1 != iter2)
```



### 练习 9.7

> 为了索引`int`的`vector`中的元素，应该使用什么类型？

```cpp
vector<int>::size_type  
```



### 练习 9.8

> 为了读取`string`的`list`中的元素，应该使用什么类型？如果写入`list`，又应该使用什么类型？

```cpp
list<string>::const_iterator // 读
list<string>::iterator   // 写   
```



### 练习 9.9

> `begin`和`cbegin`两个函数有什么不同？

`begin`返回的普通迭代器，`cbegin`返回的是常量迭代器。



### 练习 9.10

> 下面4个对象分别是什么类型？
>
> ```cpp
> vector<int> v1;
> const vector<int> v2;
> auto it1 = v1.begin(), it2 = v2.begin();
> auto it3 = v1.cbegin(), it4 = v2.cbegin();
> ```



### 练习 9.11

> 对6种创建和初始化`vector`对象的方法，每一种都给出一个实例。解释每个`vector`包含什么值。

```cpp
vector<int> vec1;	// 0
vector<int> vec2(10);	// 10个0
vector<int> vec3(10, 1);	// 10个1
vector<int> vec4{1, 2, 3, 4, 5};	//1, 2, 3, 4, 5
vector<int> vec5(other_vec);	// 拷贝other_vec的元素
vector<int> vec6(other_vec.begin(), other_vec.end());	// 拷贝other_vec的元素
```



### 练习 9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

- 接收一个容器创建其拷贝的构造函数，要求容器类型和元素类型必须相同

```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers);        // numbers2和numbers具有相同元素
vector<int> numbers3(numbers);      // 错误，类型不匹配
list<double> numbers4(numbers);     // 错误，类型不匹配
```

- 接受两个迭代器创建拷贝的构造函数，只需要元素的类型能够相互转换，容器类型和元素类型可以不同

```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers.begin(), numbers.end);	// numbers2和numbers具有相同元素
vector<int> numbers3(numbers.begin(), --numbers.end());  // numbers3 -> { 1, 2, 3, 4 }
list<double> numbers4(++numbers.beg(), --numbers.end());	// numbers4 -> { 2, 3, 4 }
forward_list<float> numbers5(numbers.begin(), numbers.end());//number5->{ 1, 2, 3, 4, 5 }
```



### 练习 9.13

> 如何从一个`list<int>`初始化一个`vector<double>`？从一个`vector<int>`又该如何创建？编写代码验证你的答案。

```cpp
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> list1(5, 4);
    vector<int> ivec(5, 5);

    vector<double> dvec1(list1.begin(), list1.end());
    vector<double> dvec2(ivec.begin(), ivec.end());
    for (auto d : dvec1)
        cout << d << " ";
    cout << endl;

    for (auto d : dvec2)
        cout << d << " ";
    cout << endl;
    return 0;
}
```



### 练习 9.14

> 编写程序，将一个`list`中的`char *`指针元素赋值给一个`vector`中的`string`。

```cpp
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<const char *> list1{"C", "C++", "Java"};
    vector<string> vec;
    vec.assign(list1.begin(), list1.end());
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
    return 0;
}
```



### 练习 9.15

> 编写程序，判定两个`vector<int>`是否相等。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{1, 2, 3, 4, 5};
    vector<int> vec3{1, 2, 3, 4};
    cout << (vec1 == vec2 ? "True" : "False") << endl;
    cout << (vec1 == vec3 ? "True" : "False") << endl;
    
    return 0;
}
```



### 练习 9.16

> 重写上一题的程序，比较一个list中的元素和一个vector中的元素。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{1, 2, 3, 4, 5};
    vector<int> vec3{1, 2, 3, 4};
    cout << (vector<int>(vec1.begin(), vec1.end()) == vec2 ? "True" : "False") << endl;
    cout << (vector<int>(vec1.begin(), vec1.end()) == vec3 ? "True" : "False") << endl;

    return 0;
}
```



### 练习 9.17

> 假定`c1`和`c2`是两个容器，下面的比较操作有何限制？

- `c1`和`c2`必须是相同类型的容器且保存相同类型的元素
- 元素类型要支持关系运算符



### 练习 9.18

> 编写程序，从标准输入读取`string`序列，存入一个`deque`中。编写一个循环，用迭代器打印`deque`中的元素。

```cpp
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<string> input;
    for (string str; cin >> str; input.push_back(str))
        ;
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;
    return 0;
}
```



### 练习 9.19

> 重写上一题的程序，用`list`替代`deque`。列出程序要做出哪些改变。

```cpp
deque<string> input; -> list<string> input;
```

