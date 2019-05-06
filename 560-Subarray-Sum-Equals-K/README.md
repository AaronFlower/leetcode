## 560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

```
Input:nums = [1,1,1], k = 2
Output: 2
```

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

### Analysis

假设用 $a_1, a_1, a_2, …, a_n $ 一组数据 ，令：
$$
S_i = \sum_{k=1}^{i}{a_i}
$$
则我们需要统计的是两种情况：

1. $S_i == k$
2. $S_i - S_j == k,  i > j$,  即 $(i, j]$ 之间的元素和等于 k 。

所以我们可以让 $Si$ 为累加和，$Si - k = S_j$ ，如果 $S_j$ 为和为 $S_j$ 时的统计数。很明显当  $Si - k = 0 $ 时，我们需要统计，所以 `map[0] = 1` 初始为 1。 所以实现的代码如下：

```c++
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), count = 0, i, sum = 0;

    unordered_map<int, int> map;

    map[0] = 1;
    for (i = 0; i < n; ++i) {
        sum += nums[i];
        count += map[sum - k];
        map[sum] ++;
    }

    return count;
}
```





