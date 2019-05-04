## Knapsack

[0-1 Knapsack](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Knapsack.svg/500px-Knapsack.svg.png)

Using Dynamic Programming to implement thd 01-knapsack problem.

### Description

> Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

#### 0-1 knapsack

0-1 knapsack 问题有两个限制条件，a) 物品要么全部装进入去，要和不装，不能只装一部分；2）一个物品只能装一次，不能复制。

#### Example

```
 int vals[]    = {7, 8, 4}
 int weights[] = {3, 8, 6}
 int capacity  = 10
```

使用动态规划生成的表如下：

```
        0       1       2       3       4       5       6       7       8       9       10
------------------------------------------------------------------------------------------
 0   |  0       0       0       0       0       0       0       0       0       0       0
 1   |  0       0       0       7       7       7       7       7       7       7       7
 2   |  0       0       0       7       7       7       7       7       8       8       8
 3   |  0       0       0       7       7       7       7       7       8       11      11

```

根据 DP 表格自己可以推算一下。
