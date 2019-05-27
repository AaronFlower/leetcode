## 设计题

设计一个数据结构，该数据结构有两种操作：

1. insert(key), 插入一个 key
2. median(), 返回数据的中位数。

插入的数保证不会重复。

- vector<int> 有序，在找到插入位置时需要移动元素，无法达到 O(lg N).
- set<int> 有序，在插入时可以保证 O (lg N), 并且需要同步记录 median 的位置。

### 注意点：

1. set 元素无法重复，其它只能用 multiset.
2. set<int>::iterator 是 associative 的，可以 ++, --, 但是不能用 +n, -n, 这样的话要用 `next(it, n), prev(it, n)` 来完成。
3. it 之间的差也不能用 -, 要用 `std::distance(begin, end);

所以 iterator 也分为：random-access iterator, 和 bidirectional iterator.

random-access iterator, 如 vector, deque 的 iterator;
bidiectional iterator, 如 map, set 的 iterator.

- [ ] c++ primer
