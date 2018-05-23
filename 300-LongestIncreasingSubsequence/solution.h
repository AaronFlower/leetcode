#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>

using std::vector;
using std::max;
using std::lower_bound;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if (m > 0) {
            vector<int> lis(m, 0);
            lis[0] = 1;
            for (int i = 1; i < m; ++i) {
                if (nums[i] > nums[i - 1]) {
                    lis[i] = 1 + lis[i - 1];
                } else {
                    int preMaxLis = 0;
                    for (int j = i - 1; j >= 0; --j) {
                        if (nums[i] > nums[j]) {
                            preMaxLis = max(preMaxLis, lis[j]);
                        }
                    }
                    lis[i] = max(preMaxLis + 1, lis[i - 1]);
                }
            }
            return lis[m - 1];
        }
        return 0;
    }

    int lengthOfLisIt(vector<int> &nums) {
        if (nums.size() == 0) return 0;

        vector<int>::iterator m = nums.begin();
        for (auto val:nums) {
            auto it = lower_bound(nums.begin(), m, val);
            *it = val;
            if (it == m) {
                m ++;
            }
        }
        return m - nums.begin();
    }
};

#endif

