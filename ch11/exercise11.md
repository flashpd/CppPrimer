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



### 练习 11.23

> 11.2.1节练习中的`map` 以孩子的姓为关键字，保存他们的名的`vector`，用`multimap` 重写此`map`。

```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> families;
    for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname))
        ;
    for (auto const &family : families)
        cout << family.second << " " << family.first << endl;

    return 0;
}
```



### 练习 11.24

> 下面的程序完成什么功能？
>
> ```cpp
> map<int, int> m;
> m[0] = 1;
> ```

将键值为0的元素赋值为1



### 练习 11.25

> 对比下面的程序与上一题程序
>
> ```cpp
> vector<int> v;
> v[0] = 1;
> ```

未定义行为，下标越界



### 练习 11.26

> 可以用什么类型来对一个`map`进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个`map`，然后写出一个可以用来对`map`进行下标操作的类型以及下标运算符将会返会的类型。

```cpp
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

int main()
{
    std::map<int, std::string> m = {{1, "ss"}, {2, "sz"}};
    using KeyType = std::map<int, std::string>::key_type;

    std::cout << "type to subscript: " << typeid(KeyType).name() << std::endl;
    std::cout << "returned from the subscript operator: " << typeid(decltype(m[1])).name() << std::endl;

    return 0;
}
```



### 练习 11.27

> 对于什么问题你会使用`count`来解决？什么时候你又会选择`find`呢？

- 允许重复关键字的容器应该用`count`
- 不允许重复关键字的容器，应该用`find`

书本388页



### 练习 11.28

> 对一个`string`到`int`的`vector`的`map`，定义并初始化一个变量来保存在其上调用`find`所返回的结果。

```cpp
map<string, vector<int>> m;
map<string, vector<int>>::iterator it = m.find("key");
```



### 练习 11.29

> 如果给定的关键字不在容器中，`upper_bound`、`lower_bound` 和 `equal_range` 分别会返回什么？

- 如果`lower_bound`和`upper_bound`返回相同的迭代器，则给定关键字不在容器中
- `equal_range`会返回一个`pair`，`pair`中的两个迭代器都指向关键字可以插入的位置

书本390页



### 练习 11.30

> 对于本节最后一个程序中的输出表达式，解释运算对象`pos.first->second`的含义。

- `pos`是一个`pair`
- `pos.first`是一个迭代器，指向第一个元素
- `pos.first->second`与`key_value`第一个元素相匹配的值



### 练习 11.31

> 编写程序，定义一个作者及其作品的`multimap`。使用`find`在`multimap`中查找一个元素并用`erase`删除它。确保你的程序在元素不在`map` 中时也能正常运行。

```cpp
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::multimap<string, string> authors{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"}};
    // want to delete an element that author is [Alan], work is [112].
    string author = "pezy";
    string work = "CP5";

    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count)
    {
        if (found->second == work)
        {
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }

    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;
}
```



### 练习 11.32

> 使用上一题定义的`multimap`编写一个程序，按字典序打印作者列表和他们的作品。

```cpp
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::multimap<string, string> authors{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"}};
    std::map<string, std::multiset<string>> order_authors;
    for (const auto &author : authors)
        order_authors[author.first].insert(author.second);
    for (const auto &author : order_authors)
    {
        std::cout << author.first << ": ";
        for (const auto &work : author.second)
            std::cout << work << " ";
        std::cout << std::endl;
    }
}
```



### 练习 11.33

> 实现你自己版本的单词转换程序。

```cpp
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using std::ifstream;
using std::string;

std::map<string, string> buildMap(ifstream &map_file)
{
    std::map<string, string> trans_map;
    for (string key, value; map_file >> key && getline(map_file, value);)
        if (value.size() > 1)
            trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
    return trans_map;
}

const string &transform(const string &s, const std::map<string, string> &m)
{
    auto map_it = m.find(s);
    return map_it == m.cend() ? s : map_it->second;
}

void word_transform(ifstream &map, ifstream &input)
{
    auto trans_map = buildMap(map);
    for (string text; getline(input, text);)
    {
        std::istringstream iss(text);
        for (string word; iss >> word;)
            std::cout << transform(word, trans_map) << " ";
        std::cout << std::endl;
    }
}

int main()
{
    ifstream ifs_map("word_transformation_bad.txt"), ifs_content("given_to_transform.txt");
    if (ifs_map && ifs_content)
        word_transform(ifs_map, ifs_content);
    else
        std::cerr << "can't find the documents." << std::endl;
}
```



### 练习 11.34

> 如果你将`transform` 函数中的`find`替换为下标运算符，会发生什么情况？

使用下标运算符，当关键字不在容器中时，回望容器中添加一个新的元素



### 练习 11.35

> 在`buildMap`中，如果进行如下改写，会有什么效果？
>
> ```cpp
> trans_map[key] = value.substr(1);
> //改为
> trans_map.insert({key, value.substr(1)});
> ```

当一个转换规则的关键字多次出现的时候，使用下标运算符会保留最后一次添加的规则，而`insert`保留第一次添加的规则



### 练习 11.36

> 我们的程序并没检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。

如果关键字没有对应的规则，那么程序会抛出一个`runtime_error`



### 练习 11.37

> 一个无序容器与其有序版本相比有何优势？有序版本有何优势？

- 无序容器：更好的性能
- 有序容器：元素有序



### 练习 11.38

> 用 `unordered_map` 重写单词计数程序和单词转换程序。

```cpp
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;

void wordCounting()
{
    std::unordered_map<string, size_t> word_count;
    for (string word; std::cin >> word; ++word_count[word])
        ;
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? "times" : "time") << std::endl;
}

void wordTransformation()
{
    std::ifstream ifs_map("word_transformation.txt"), ifs_content("given_to_transform.txt");
    if (!ifs_map || !ifs_content)
    {
        std::cerr << "can't find the documents." << std::endl;
        return;
    }

    std::unordered_map<string, string> trans_map;
    for (string key, value; ifs_map >> key && getline(ifs_map, value);)
        if (value.size() > 1)
            trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));

    for (string text, word; getline(ifs_content, text); std::cout << std::endl)
        for (std::istringstream iss(text); iss >> word;)
        {
            auto map_it = trans_map.find(word);
            std::cout << (map_it == trans_map.cend() ? word : map_it->second) << " ";
        }
}

int main()
{
    //wordCounting();
    wordTransformation();
}
```

