## 32. Longest Valid Parentheses

### Descripttion

Given a string containing just the characters `(` and `)`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

```
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
```

**Example 2:**

```
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
```

### Analysis

$$
str  = s_0...s_{k-2}s_{k-1}s_k...s_{i-1}s_i...s_n
$$

Given above $str$, we create an array `length` to store the max length of every index of the string. So the value of `length(i)` has the next formula.
$$
length(i) =
  \begin{cases}
    0       & \quad \text{if } s_i  = \text{'('}\\
    length(i - 2) + 2  & \quad \text{if }  s_i  = \text{')', }  s_{i-1}  = \text{'('} \\
    length(i - 1) + 2 + length(k - 2)  & \quad \text{if }  s_i  = \text{')', }  s_{i-1}  = \text{')'},  s_{k-1}  = \text{'(' ,} \\ & \quad \text{which }  k = i - length(i - 1), 
  \end{cases}
$$
