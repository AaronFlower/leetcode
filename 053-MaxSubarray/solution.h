#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>

using std::vector;
using std::max;

class Solution {
public:
    int maxSubarray(vector<int> &nums) {
        int m = nums.size();
        if (m > 0) {
            int curSum = 0;
            int sum = nums[0];
            for (int i = 0; i < m; ++i) {
                curSum += nums[i];
                if (curSum > sum) sum = curSum;
                if (curSum < 0) curSum = 0;
            }
            return sum;
        }
        return 0;
    }

    int maxSubarrayBig_On2(vector<int> &nums) {
        int m = nums.size();
        if (m > 0) {
            vector<vector<int>> sums(m, vector<int>(m, 0));
            sums[0] = nums;
            int maxSum = nums[0];
            for (auto v:nums) maxSum = max(maxSum, v);

            for (int i = 1; i < m; ++i) {
                for (int j = 0; i + j < m; ++j) {
                    sums[i][j] = sums[i - 1][j] + nums[i + j];
                    maxSum = max(maxSum, sums[i][j]);
                }
            }
            return maxSum;
        }
        return 0;
    }
};

#endif

