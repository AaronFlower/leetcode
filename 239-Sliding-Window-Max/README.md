## 239. Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

```
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

### Analysis

#### 1. Naive , O(nk)

给定一个数组 arr[n] 和一个大小为 k 的滑动窗口，窗口从左向右滑动，返回每一个滑动窗口的最小值。

即对于 i 属于 [k-1, n), min (arr[i-k+1], arr[i - k], arr[i - k - 1], ..., arr[i - 1], arr[i]); 那么在一个数组中我们一共有 (n - k + 1) 个窗口，而每个容器的个数为 k, 在数组中寻找最大值的时间复杂度为 lg(k), 所以如果用朴素的算法，时间复杂度为 O((n - k + 1)k) 即为 O(nk).

算法可以写成如下的形式：

```c++
vector<int> maxSlidingWindowNaive(vector<int> &nums, int k) {
    vector<int> res;
    int i, j, max;
    int len = nums.size();

    for (i = 0; i < len - k +1; ++i) {
        max = nums[i];
        for (j = i + 1; j < i + k ; ++j) {
            max = max > nums[j] ? max : nums[j];
        }
        res.push_back(max);
    }
    return res;
}
```

#### 2. Multiset, O(nlgk)

使用 Multiset.

1. Multiset 的所有操作(search, insertion, removal) 都是 O(lgK);
2. Multiset 支持按 key 删除, 即`erase(key)`;
3. Multiset 默认的 compare functor 是 less, 即按升序排序；

在实现时，因为我想让 Multiset 按降序排序，即按 greater 排序，我们可以传一个 greater, 不过我们仅仅在前面加一个负号也能解决这个问题。

```c++
vector<int> maxSlidingWindowMultiSet(vector<int> &nums, int k) {
    vector<int> res;
    multiset<int> s;

    for (int i = 0; i < (int)nums.size(); ++i) {
        s.insert(- nums[i]);
        if (i >= k - 1) {
            res.push_back(- *s.begin());
            s.erase(- nums[i - k + 1]);
        }
    }
    return res;
}
```

#### 3. Heap, O(nlgk)

使用 heap 也能实现 multiset 实现的效果，因为 heap 的所有操作也是 O(lgk), 但是从实际的效果来看 heap 效率更好些。

1. c++ 的 stl 并没直接提供 heap, 我们可以使用 priority_queue 来实现。
2. priority_queue 不支持指定 key 删除。
3. priority_queue 默认是降序的，max-heap.

因为在堆中希望根据 key 来删除元素，但是在 C++ 中实现的堆(std::priority_queue)并不支持这种特性。所以我们可以使用 delete lazily 策略, 即对于每个 priority_queue 中的元素我也会存储它的下标。然后在滑动到下一个窗口时，我们会检查当前容器的最大元素(`top()`)的下标是否超出了下一个容器的下标范围，如果超出了下一窗口的范围，就将其删除。

```c++
vector<int> maxSlidingWindowHeap1(vector<int> &nums, int k) {
    vector<int> res;
    priority_queue<pair<int, int>> q;

    for (int i =0; i < k; ++i) {
        q.push({nums[i], i});
    }
    res.push_back(q.top().first);

    int len = nums.size();
    for (int i = k; i < len; ++i) {
        // 如果最大值的下标还在下一个窗口的范围内就继续保留，否则就删除。delete-lazily
        while (q.top().second <= i - k) {
            q.pop();
        }
        q.push({nums[i], i});
        res.push_back(q.top().first);
    }

    return res;
}

```

我们可以优化到一个循环中完成。

```c++
vector<int> maxSlidingWindowHeap2(vector<int> &nums, int k) {
    vector<int> res;
    priority_queue<pair<int, int>> q;

    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        while (!q.empty() && q.top().second <= i - k) {
            q.pop();
        }
        q.push({nums[i], i});
        if (i >= k - 1) {
            res.push_back(q.top().first);
        }
    }
    return res;
}
```

#### 4. deque, O(n)

1. deque 允许在两端进行操作, 并且不使两端的指针失效；
2. Insertion or removal of elements at the end or beginnig - constant O(1)
3. Random access - constant(1)
4. Insertion or removal of elements - linear O(n)

deque 的内部实现并不是连续存储的, typical implementations use a sequence of individually allocated fixed-size arrays, with additional bookkeeping, which means indexed access to deque must perform two pointer dereferences, compared to vector's indexed access which performs only one.

使用 deque 只在两端操作，就可以完成操作。我们的算法设计思路为：

1. 我们维护的 deque 是一个降序 queue, 即头部元素是最大元素;
2. 从尾部插入元素时首先，删除为该元素小的，直接找到合适的插入位置；
3. 从头部取走元素后，删除下标超出下一个滑动窗口下标范围的元素；

```c++
vector<int> maxSlidingWindowDeque2(vector<int> &nums, int k) {
    deque<pair<int, int>> q;  // 创建的是一个降序 deque, 队首永远是最大的元素
    vector<int> res;

    for (int i = 0; i < (int)nums.size(); ++i) {

        // 先从尾向头删除到可以插入的位置
        while (!q.empty() && q.back().first <= nums[i]) {
            q.pop_back();
        }

        q.push_back({nums[i], i});

        if (i >= k - 1) {
            res.push_back(q.front().first);
        }

        // 再从头向尾删除超出范围的元素
        while (!q.empty() && q.front().second <= i - k) {
            q.pop_front();
        }
    }
    return res;
}

```

Pretty Sweet 😉

### References

1.[Sliding Window Minimum Implementations](https://people.cs.uct.ac.za/~ksmith/articles/sliding_window_minimum.html)
