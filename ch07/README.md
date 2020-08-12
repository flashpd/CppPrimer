本章代码参考：https://github.com/Mooophy/Cpp-Primer/tree/master/ch07



## Exercise 7.1



## Exercise 7.2



## Exercise 7.3



## Exercise 7.4



## Exercise 7.5



## Exercise 7.6



## Exercise 7.7



## Exercise 7.8

read里需要改变对象的值所以定义为普通引用

print里不需要改变对象的值，所以定义为普通引用



## Exercise 7.9



## Exercise 7.10

```c++
if(read(read(cin, data1), data2))
```

先从cin中读取信息到data1中，然后从data1中读取信息到data2中



## Exercise 7.11



## Exercise 7.12





## Exercise 7.18

封装：隐蔽细节，提供接口

优点：确保用户代码不会无意间破坏封装对象的状态，被封装的类的具体实现细节可以随时改变，而无须调整用户级别的代码。



## Exercise 7.19

当需要让其他类或者函数访问当前类的非公有成员的时候可以使用友元

好处：可以访问类的非公有成员

坏处：破坏类的封装性



## Exercise 7.22

