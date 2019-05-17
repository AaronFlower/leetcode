## C++ 实现比较函数的三种方法

C++ 中很多的 STL 方法和容器都开发者定义集合中的对象之间的比较顺序。所以知道如何在类中定义一个排序方法是很重要的。

### 1. How to Define Ordering?

In a nutshell, 定序是指定义 T 的两个对象 a, b 之间的顺序，我们可确定 a 是否排在 b 的前面。这种定义通过实现一个返回 bool 类型的函数来实现。

### 2. 严格弱序 (Strict Weak Ordering)

几乎所有的函数、容器（除了 `priority_queue<T>`）都要求定向满足数学中*严格弱序* 的定义，否则的话函数和容器的行为将是未定义的 (undefined)。

假设 `f(x, y)` 是一个严格弱序函数，则它满足下面四个约束条件：

1. **Irreflexivity** （反自反性）

   `f(x, x) =false`

2. **Antisymmetry** (反对称性)

   `if f(x, y) then !f(y, x)`

3. **Transitivity**(传递性)

   `if f(x, y) and f(y, z) then f(x, z)`

4. **Transitivity of Equivalence**(等价传递性)

   定义一个相等函数为: `equal(x, y) = !f(x,y) && !f(y, x)`, 即 x 不优先于 y , y 也不优先于 x . 如果 `equal(x, y) and equal(y, z) then equal(x, z)`。

### 3. 定序实现方法

#### 3.1 重载 `<` 运算符

如果现实现自定义类型的排序，可以重载 `<` 运算符。如在实现 Kruskal 算法时， 我们期望权重大的边排在前面，我们可以用下面的方法实现 `Edge` 。

```c++
struct Edge	{
	int from, to;
    int weight;
    
    bool operator<(Edge other) const {
        return weight > other.weight
    }
};
```

即我们实现了下面的函数原型。

```c++
bool operator<(T other) const;
```

当然你也可以用友元函数来实现对运算符 `<` 的重载。代码如下：

```c++
struct Edge {
    int from, to;
    int weight;
    friend bool operator<(Edge a, Edge b) {
        return a.weight < b.weight;
    }
};
```

对于重载了 `<` 运算符的类，我们就可以直接使用 STL 函数:

```c++
vector<Edge> v;
sort(v.begin(), v.end());
```

和 STL 容器了, 如：

```c++
priority_queue<Edge> pq;
set<Edge> s;
```

### 3.2 自定义一个比较函数

对于比较不能修改的内置数据类型，或者不可以修改的类，或者想我重写类型的默认定序，我们可以使用自定义比较函数的方法。

比较函数的原型是：

```c++
bool name(T a, T b)
```

例如，假设有两个数组, `vector<int> data, vector<int> occurrence`, 你想对 `data`中每个值根据其在 `occurences` 中的出现次数来进行升序排序，你可以定义下面的函数:

```c++
bool cmp(int a, int b) {
    return occurences[a] < occurences[b];
}
```

这样就可以使用下的方法来实现排序了：

```c++
sort(data.begin(), data.end(), cmp);
```

### 3.3 重载 `()`运算符

在使用 STL 容器时，容器提供的构造函数支持传入比较函数来初始化容器实例。如：

```c++
bool cmp(int a, int b);
set<int, bool (*)(int, int)> s(cmp);
```

基中，`set` 模版的第二个类型是`函数指针类型`. 我也可以使用 `decltype` 来简化:

```c++
set<int, decltype(cmp)> s(cmp);
```

但是这种方法，对于不太熟悉语法的可能会感到迷惑。

我们还可以能过定义 `functor or function object`的方法来实现对容器的初始化。一个 functor (函子) 就是其行为和函数类似的对象。通过重载 `()`运算符就可以实现。如:

```c++
vector<int> occurrences;
struct cmp {
    bool operator()(int a, int b) {
        return occurrences[a] < occurrences[b];
    }
}
```

接下来我们初始化容器就可以很简单了。

```c++
set<int, cmp> s;
priority_queue<int, vector<int>, cmp> pq;
```

STL 也提供了内置的函子，如`less<T>, greater<T>`。其中默认的是 `less<T>`, 如果想倒序排序的话，可以使用下面的方法:

```c++
sort(data.begin(), data.end(), greater<int>());
```

### 4. Tips

#### 4.1 `const T&`

如果类型很复杂时，可以使用常引用来传递参数，即可提高性能，也可以保证参数学被修改。

#### 4.2 sort() v.s. stable_sort()

`stable_sort()`可以保证稳定排序 。

### 参考

1. [3 Ways to Define Comparison Functions in C++](3 Ways to Define Comparison Functions in C++)


