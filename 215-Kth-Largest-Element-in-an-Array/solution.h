#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <queue>
#include <functional>

using std::vector;
using std::priority_queue;
using std::greater;

struct greatCmp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 使用 STL 提供的函数对象
        priority_queue<int, vector<int>, greater<int>> q;

        for (int i : nums) {
            q.push(i);
            if ((int)q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }

    int findKthLargest1(vector<int> &nums, int k) {
        // 使用自定义的函数对象
        priority_queue<int, vector<int>, greatCmp> q;

        for (int n:nums) {
            q.push(n);
            if ((int)q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }

    int findKthLargest2(vector<int> &nums, int k) {
        // 使用 lambda 函数，但是要复杂一点。
        auto cmp = [](const int &a, const int &b) {return a > b;};
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

        for (int n:nums) {
            q.push(n);
            if ((int)q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};

#endif
