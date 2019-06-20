## 301. Remove Invalid Parentheses
### Description

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

```
Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:
```

```
Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
```

### Analysis

知识点：

1. 如何判断一组括号是否合法那？有两咱方法：用栈和统计。(stack vs. counter) counter 更简单效率更高些。
