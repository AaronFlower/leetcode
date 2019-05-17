#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <queue>
#include <set>

using std::vector;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::multiset;
using std::deque;

class Solution
{
public:
    /**
     * 使用 deque 和 heap 的方法一样。
     */
    vector<int> maxSlidingWindowDeque1(vector<int> &nums, int k) {
        deque<pair<int, int>> q;
        vector<int> res;
        int len = nums.size();

        if (len > 0) {
            q.push_back({nums[0], 0});
            for (int i = 1; i < k - 1; ++i) {
                if (nums[i] >= q.front().first) {
                    q.push_front({nums[i], i});
                } else {
                    q.push_back({nums[i], i});
                }
            }

            for (int i = k - 1; i < len; ++i) {
                if (!q.empty() && nums[i] >= q.front().first) {
                    q.push_front({nums[i], i});
                } else {
                    q.push_back({nums[i], i});
                }

                res.push_back(q.front().first);

                while (!q.empty() && q.front().second <= i - k) {
                    q.pop_front();
                }
            }
        }
        return res;
    }

    /**
     * 使用 deque 优化下循环
     */
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

    /**
     * Naive
     */
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

    /**
     * 用 heap 来实现，删除 heap 的 top() 时检查其下标是否超过下一个窗口的下标范围。
     */
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


    /**
     * 用 heap 来实现，删除 heap 的 top() 时检查其下标是否超过下一个窗口的下标范围, 代码优化。
     */
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

    /**
     * 用 multiset 实现。multiset 支持重复的 key, 默认是按 less 排序的。
     */
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
};

#endif
