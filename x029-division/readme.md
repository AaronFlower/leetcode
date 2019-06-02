## Divide two integers without using multiplication, division and mod operator

Given a two integers say a and b. Find the quotient and remainder after dividing a by b without using multiplication, division and mod operator.

Example:

```c
Input : a = 10, b = 3
Output : quotient = 3, remainder = 1

Input : a = 43, b = -8
Output : quotient = -5, remainder = -3

```

在不使用乘法、除法、取余操作求出两个整数的商和余数。

### Analysis

为了求解方便，我们只对自然数求解，即正整数。

1. 第一种解法利用减法：

即当 a >= b 时，就可以用 a -= b, 一直到 a < b 结束循环，这样循环次数就是 quotient, 而 remainder 是余数。

该算法的复杂度是 O(a), 即当 b = 1 时是最坏的情况。

2. 第二种解法利用移位：

第一种方法每次的累加的数都是 b。我们可不可以利用贪心的算法从不大于 a 的最大数来累加那？ 当然可以，那么怎么找到下一个可以使用的最大累加数那？

我们可以让 b 向左移位，直到找到最接近但不大于 a 的数，然后进行累加。然后再继续寻找下一个可累加值。这样的话我们可从高位向低的方向来寻找，而不是从低向高来寻找下一个最大的可累加值。

**注意**: 左移要注意溢出的情况。

3. 第三种解法利用 log:

假设我们只求 quotient 的话，可以利用对数的性质：

log(a) - log(b) = log (a/b) , 所以 (a/b) = exp(log(a) - log(b))

### Definition

先来看下商与余数的定义：

定义1： 自然数中的定义，如果 a, b 是两个自然数并且 `b != 0`, 则可以证明存在惟一的一对自然数 q 和 r, 满足 a / b = b * q + r,  0 <= r < q。 q (quotient) 商，r (remainder) 余数。

By the way, a 称为被除数(dividend)， b 称为除数(divisor).

如: a = 7, b = 3, 则 7 / 3 = 3 * 2 + 1, q = 2, r = 1。

对于自然数的定义没什么问题，但是如果a, b 期中一个为负数上面的定义就不能适用了。

如: a = -7, b = 3, 则会出现两种情况：
    -7 / 3 = 3 * (-3) + 2, q = -3, r = 2,  r 并不小于 q
    -7 / 3 = 3 * (-2) + -1, q = -2, r = -1,  r 并不小于 q

再如: a = 7, b = -3 , 也是有两种情况：
    7 / -3 = -3 * -2 + 1, q = -2, r = 1, r 并不小于 q
    7 / -3 = -3 * -3 - 2, q = -3, r = -2, r 小于 q
又如：a = -7, b = -3, 也是有两种情况：
    -7 / -3 = -3 * 2 - 1, q = 2, r = -1, r 小于 q
    -7 / -3 = -3 * 3 + 2, q = 3, r = 2, r 小于 q

所以对于整数的定义余数，当出现负数时会有两种情况，其定义如下：

a, b 是整数，b != 0, 存在一对整数 q, r；使得: a = bq + r, 且 0 <= |r| < |q|.

- [ ] 当有负整数时能不能给出一个统一的定义那？ 比如定义齿轮的方向，9 / 4, 大轮盘有 9 个齿，小轮盘有 4 个齿，求解时，小轮盘转 2 圈即是商，而大轮盘还有一个齿就是余数。

### References

1. [实数范围内的求模（求余）运算：负数求余究竟怎么求](http://ceeji.net/blog/mod-in-real/)
