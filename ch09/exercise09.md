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

