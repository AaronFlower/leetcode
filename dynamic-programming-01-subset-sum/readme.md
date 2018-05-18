## Description

Given a set of non-negative integers, and a value *sum*, determine if there is a subset of the given set with sum equal to given *sum*.

```
Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.
```

## Analysis

One set has 2^n subsets as the set has n elements. So, it's mad to use brute force method to solve the problem. Dynamic Programming is the way to solve the problem.

### Step 1 Find the Subproblem

For a set has number n elements, to check if has subset sum equals `total`.  `checkIsSubsetSum(arr, n, total)`. There are two cases for the current state.

Case 1: if `arr[n]` is one part of `total`, we need to find ``checkIsSubsetSum(arr, n - 1, total - a[n - 1])`,  AKA we need to minus `arr[n - 1]`.

Case 2: Otherwise, `arr[n]` is not one part of `total`, we need to find ``checkIsSubsetSum(arr, n - 1, total) `,AKA we don't need to minus `arr[n - 1]`.

By the way, when arr[n] > total we just have case 2, otherwise we have two cases.

Base cases: 

```c++
checkIsSubsetSum(arr, n, total) = false, when n == 0, total > 0
checkIsSubsetSum(arr, n, total) = true, when n == 0, total == 0
```

