### 练习 11.1

> 描述`map`和`vector`的不同。

`map`是关联容器，`vector`是顺序容器



### 练习 11.2

> 分别给出最适合使用`list`、`vector`、`deque`、`map`以及`set`的例子。

- `list`：双向链表，适合频繁插入删除元素的场景
- `vector`：适合频繁访问元素的场景
- `deque`：双端队列，适合在首尾频繁插入删除元素的场景
- `map`：字典
- `set`：适合有序不重复的元素的场景



### 练习 11.3

> 编写你自己的单词计数程序。

```cpp
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> word_count;
    string tmp;
    while (cin >> tmp)
        word_count[tmp] += 1;

    for (const auto &elem : word_count)
        cout << elem.first << " : " << elem.second << endl;

    return 0;
}
```



### 练习 11.4

> 扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。





### 练习 11.5

> 解释`map`和`set`的区别。你如何选择使用哪个？

`map`存储的键值对，`set`只用来判断键是否存在



### 练习 11.6

> 解释`set`和`list`的区别。你如何选择使用哪个？

- `set`是有序不重复集合，底层实现是红黑树
- `list`是无序可重复集合，底层实现是链表



### 练习 11.7

> 定义一个`map`，关键字是家庭的姓，值是一个`vector`，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

```cpp
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
using Families = map<string, vector<string>>;

auto make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's name:\n", cin >> cn && cn != "@q";)
            families[ln].push_back(cn);

    return families;
}

auto print(Families const &families)
{
    for (auto const &family : families)
    {
        cout << family.first << ":\n";
        for (auto const &child : family.second)
            cout << child << " ";

        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
```



### 练习 11.8

> 编写一个程序，在一个`vector`而不是一个`set`中保存不重复的单词。使用`set`的优点是什么？

`set`的优点是元素不重复

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> exclude = {"aa", "bb", "cc", "dd", "ee", "ff"};
    for (string word; cout << "Enter plz:\n", cin >> word;)
    {
        auto is_exclude = binary_search(exclude.cbegin(), exclude.cbegin(), word);
        auto reply = is_exclude ? "exclude" : "not exclude";
        cout << reply << endl;
    }

    return 0;
}
```



### 练习 11.9

> 定义一个`map`，将单词与一个行号的`list`关联，`list`中保存的是单词所出现的行号。

```cpp
map<string, list<size_t>> m;
```



### 练习 11.10

> 可以定义一个`vector<int>::iterator` 到 `int` 的`map`吗？`list<int>::iterator` 到 `int` 的`map`呢？对于两种情况，如果不能，解释为什么。

前者可以，后者不行，因为`map`的键必须实现`<`操作，`list`的迭代器不支持比较运算。



### 练习11.11

> 不使用`decltype` 重新定义 `bookstore`。

~~早已忘记啥是decltype~~

```cpp
using Less = bool (*)(Sales_data const&, Sales_data const&);
std::multiset<Sales_data, Less> bookstore(less);
```



### 练习 11.12

> 编写程序，读入`string`和`int`的序列，将每个`string`和`int`存入一个`pair` 中，`pair`保存在一个`vector`中。

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<pair<string, int>> vec;
    string str;
    int i;
    while (cin >> str >> i)
        vec.push_back(pair<string, int>(str, i));

    for (const auto &p : vec)
        cout << p.first << ":" << p.second << endl;

    return 0;
}
```



### 练习 11.13

> 在上一题的程序中，至少有三种创建`pair`的方法。编写此程序的三个版本，分别采用不同的方法创建`pair`。解释你认为哪种形式最易于编写和理解，为什么？

```cpp
vec.push_back(std::make_pair(str, i));
vec.push_back({ str, i });
vec.push_back(std::pair<string, int>(str, i)); 
```

第三种更好理解



### 练习 11.14

> 扩展你在11.2.1节练习中编写的孩子姓达到名的`map`，添加一个`pair`的`vector`，保存孩子的名和生日。

```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Families
{
public:
    using Child = pair<string, string>;
    using Children = vector<Child>;
    using Data = map<string, Children>;

    void add(string const &last_name, string const &first_name, string birthday)
    {
        auto child = make_pair(first_name, birthday);
        _data[last_name].push_back(child);
    }

    void print() const
    {
        for (auto const &pair : _data)
        {
            cout << pair.first << ":\n";
            for (auto const &child : pair.second)
                cout << child.first << " " << child.second << endl;

            cout << endl;
        }
    }

private:
    Data _data;
};
int main()
{
    Families families;
    auto msg = "Please enter last name, first name and birthday:\n";
    for (string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b))
        ;
    families.print();

    return 0;
}
```



### 练习 11.15

> 对一个`int`到`vector<int>的map`，其`mapped_type`、`key_type`和 `value_type`分别是什么？

- `mapped_type`：`vector<int>`
- `key_type`：`int`
- `value_type`：`pair<const int, vector>`



### 练习11.16

> 使用一个`map`迭代器编写一个表达式，将一个值赋予一个元素。

```cpp
map<int, string>::iterator it = m.begin();
it->second = "C++";
```



### 练习 11.17

> 假定`c`是一个`string`的`multiset`，`v` 是一个`string` 的`vector`，解释下面的调用。指出每个调用是否合法：
>
> ```cpp
> copy(v.begin(), v.end(), inserter(c, c.end()));
> copy(v.begin(), v.end(), back_inserter(c));
> copy(c.begin(), c.end(), inserter(v, v.end()));
> copy(c.begin(), c.end(), back_inserter(v));
> ```

没整明白



### 练习 11.18

> 写出第382页循环中`map_it` 的类型，不要使用`auto` 或 `decltype`。

不会，下下一道



### 练习 11.19

> 定义一个变量，通过对11.2.2节中的名为 `bookstore` 的`multiset` 调用`begin()`来初始化这个变量。写出变量的类型，不要使用`auto` 或 `decltype`。

不会，下一道



### 练习 11.20

> 重写11.1节练习的单词计数程序，使用`insert`代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。

这个版本的最好理解，因为使用了`insert`，看着更舒服（`insert`有返回值，可以明确的体现出插入操作的结果。

```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> counts;
    for (string word; cin >> word;)
    {
        auto result = counts.insert({word, 1});
        if (!result.second)
            ++result.first->second;
    }

    for (auto const &count : counts)
        cout << count.first << " " << count.second << ((count.second > 1) ? " times\n" : " time\n");

    return 0;
}
```



