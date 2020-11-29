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





