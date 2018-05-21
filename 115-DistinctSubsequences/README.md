## 115. Distinct Subsequences

### Description

Given a string **S** and a string **T**, count the number of distinct subsequences of **S** which equals **T**.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

**Example 1:**

```
Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
```

**Example 2:**

```
Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
```

### Analysis

For `s[0..m-1], t[0..n-1]`. we define `count[i][j]` stands for distinct subsequences. 

###Two Cases

#### 1. Boundary Cases

For  `s[0..i-1]  vs ""` , the distinct subsequence always be one. For `"" vs t[0..j-1]` the distinct subsequence always be zero.

#### 2. General Cases

##### Subcase 1   `s[i - 1] == t[j - 1]`

we have:

````c++
count[i][j] = count[i - 1][j - 1] + count[i][j - 1];
````

##### Subcase 2  `s[i - 1] != t[j - 1]`

```c++
count[i][j] = count[i][j - 1];
```



### Comparision: 2883ms vs 0ms

```bash
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from NumDistinct
[ RUN      ] NumDistinct.NaiveRecursive
[       OK ] NumDistinct.NaiveRecursive (2883 ms)
[ RUN      ] NumDistinct.DP
[       OK ] NumDistinct.DP (0 ms)
[----------] 2 tests from NumDistinct (2883 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (2883 ms total)
[  PASSED  ] 2 tests.
```

