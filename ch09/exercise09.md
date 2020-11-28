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



### 练习 9.20

> 编写程序，从一个`list<int>`拷贝元素到两个`deque`中。值为偶数的所有元素都拷贝到一个`deque`中，而奇数值元素都拷贝到另一个`deque`中。

```cpp
#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> list1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> odd, even;
    for (auto li : list1)
        (li & 0x1 ? odd : even).push_back(li);

    for (auto o : odd)
        cout << o << " ";
    cout << endl;

    for (auto e : even)
        cout << e << " ";
    cout << endl;

    return 0;
}
```



### 练习 9.21

> 如果我们将第308页中使用`insert`返回值将元素添加到`list`中的循环程序改写为将元素插入到`vector`中，分析循环将如何工作。

一样的工作，书上308页

> 第一次调用 `insert` 会将我们刚刚读入的 `string` 插入到 `iter` 所指向的元素之前的位置。`insert` 返回的迭代器恰好指向这个新元素。我们将此迭代器赋予 `iter` 并重复循环，读取下一个单词。只要继续有单词读入，每步 while 循环就会将一个新元素插入到 `iter` 之前，并将 `iter` 改变为新加入元素的尾置。此元素为（新的）首元素。因此，每步循环将一个元素插入到 `list` 首元素之前的位置。



### 练习 9.22

> 假定`iv`是一个`int`的`vector`，下面的程序存在什么错误？你将如何修改？
>
> ```cpp
> vector<int>::iterator iter = iv.begin(),
> 					  mid = iv.begin() + iv.size() / 2;
> while (iter != mid)
> 	if (*iter == some_val)
> 		iv.insert(iter, 2 * some_val);
> ```

循环无法结束，迭代器可能失效

```cpp
while (iter != mid)
{
    if (*iter == some_val)
    {
        iter = v.insert(iter, 2 * some_val);
        ++iter;
    }
    ++iter;
}
```



### 练习 9.23

>在本节第一个程序中，若`c.size()` 为1，则`val`、`val2`、`val3`和`val4`的值会是什么？

都是同一个值



### 练习 9.24

> 编写程序，分别使用`at`、下标运算符、`front` 和 `begin` 提取一个`vector`中的第一个元素。在一个空`vector`上测试你的程序。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(1, 1);
    cout << v.at(0) << endl;
    cout << v[0] << endl;
    cout << v.front() << endl;
    cout << *v.begin() << endl;

    return 0;
}
```



### 练习 9.25

> 对于第312页中删除一个范围内的元素的程序，如果 `elem1` 与 `elem2` 相等会发生什么？如果 `elem2` 是尾后迭代器，或者 `elem1` 和 `elem2` 皆为尾后迭代器，又会发生什么？

1. 如果`elem1`和`elem2`相等，那么什么也不改变
2. 如果`elem2`是尾后迭代器，那么从`elem1`到最后的所有元素都将被删除
3. 同1



### 练习 9.26

> 使用下面代码定义的`ia`，将`ia`拷贝到一个`vector`和一个`list`中。是用单迭代器版本的`erase`从`list`中删除奇数元素，从`vector`中删除偶数元素。
>
> ```cpp
> int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
> ```

```cpp
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    vector<int> vec(ia, end(ia));
    list<int> lst(vec.begin(), vec.end());

    for (auto it = lst.begin(); it != lst.end();)
        if (*it & 0x1)
            it = lst.erase(it);
        else
            ++it;

    for (auto it = vec.begin(); it != vec.end();)
        if (!(*it & 0X1))
            it = vec.erase(it);
        else
            ++it;

    cout << "list:";
    for (auto i : lst)
        cout << i << " ";

    cout << "\nvector: ";
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}
```



### 练习 9.27

> 编写程序，查找并删除`forward_list<int>`中的奇数元素。

```cpp
#include <iostream>
#include <forward_list>

using namespace std;

auto remove_odds(forward_list<int> &flist)
{
    auto is_odd = [](int i) { return i & 0x1; };
    flist.remove_if(is_odd);
}

int main()
{
    forward_list<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_odds(data);
    for (auto i : data)
        cout << i << " ";
    cout << endl;
    return 0;
}
```



### 练习 9.28

> 编写函数，接受一个`forward_list<string>`和两个`string`共三个参数。函数应在链表中查找第一个`string`，并将第二个`string`插入到紧接着第一个`string`之后的位置。若第一个`string`未在链表中，则将第二个`string`插入到链表末尾。

```cpp
void find_and_insert(forward_list<string> &fList, string const &to_find, string const &to_add)
{
    auto prev = fList.before_begin();
    for (auto curr = fList.begin(); curr != fList.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            fList.insert_after(curr, to_add);
            return;
        }
    }
    fList.insert_after(prev, to_add);
}
```



### 练习 9.29

> 假定`vec`包含25个元素，那么`vec.resize(100)`会做什么？如果接下来调用`vec.resize(10)`会做什么？

1. `vec.resize(100)`后，在`vec`尾部添加75个值为0的元素
2. 调用`vec.resize(10)`会从`vec`末尾删除90个元素



### 练习 9.30

> 接受单个参数的`resize`版本对元素类型有什么限制（如果有的话）？

元素类型必须提供一个默认构造函数（书本314页）



### 练习 9.31

> 第316页中删除偶数值元素并复制奇数值元素的程序不能用于`list`或`forward_list`。为什么？修改程序，使之也能用于这些类型。



### 练习 9.32

> 在第316页的程序中，向下面语句这样调用`insert`是否合法？如果不合法，为什么？
>
> ```cpp
> iter = vi.insert(iter, *iter++);
> ```

不合法



### 练习 9.33

> 在本节最后一个例子中，如果不将`insert`的结果赋予`begin`，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

如果不将`insert`的结果赋予`begin`将会使`begin`失效

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto cur = data.begin(); cur != data.end(); ++cur)
        if (*cur & 0x1)
            cur = data.insert(cur, *cur), ++cur;

    for (auto i : data)
        cout << i << " ";

    cout << endl;
    return 0;
}
```



### 练习 9.34

> 假定`vi`是一个保存`int`的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
>
> ```cpp
> iter = vi.begin();
> while (iter != vi.end())
> 	if (*iter % 2)
> 		iter = vi.insert(iter, *iter);
> 	++iter;
> ```

无限循环



### 练习 9.35

> 解释一个`vector`的`capacity`和`size`有何区别。

- `capacity`是在不分配新的内存空间的前提下最多可以保存多少元素
- `size`是指该容器已经保存的元素数目

书本318页



### 练习 9.36

> 一个容器的`capacity`可能小于它的`size`吗？

不可能



### 练习 9.37

> 为什么`list`或`array`没有`capacity`成员函数？

`list`是链表，`array`是固定大小



### 练习 9.38

> 编写程序，探究在你的标准实现中，`vector`是如何增长的。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "size(): " << vec.size() << "   capacity(): " << vec.capacity() << endl;
    for (int i = 1; i < 10; i++)
    {
        vec.push_back(i);
        cout << "size(): " << vec.size() << "   capacity(): " << vec.capacity() << endl;
    }

    cout << endl;
    return 0;
}
```



### 练习 9.39

> 解释下面程序片段做了什么：
>
> ```cpp
> vector<string> svec;
> svec.reserve(1024);
> string word;
> while (cin >> word)
> 	svec.push_back(word);
> svec.resize(svec.size() + svec.size() / 2);
> ```

1. 定义一个`vector`容器`svec`
2. 为它分配1024个字节
3. 从标准输入中读取字符串，并添加到`svec`中（如果超出1024，可能会引起重新分配）
4. 将`svec`的`size`修改为当前`size`的1.5倍



### 练习 9.40

> 如果上一题的程序读入了256个词，在`resize`之后容器的`capacity`可能是多少？如果读入了512个、1000个、或1048个呢？

- 读入256个词时，`capacity`是1024
- 读入512个词时，`capacity`是1024
- 读入1000个词时，`capacity`是1500
- 读入1048个词时，`capacity`是2048

最后两个是根据本机环境进行推算的，实际情况要看`capacity`的具体实现