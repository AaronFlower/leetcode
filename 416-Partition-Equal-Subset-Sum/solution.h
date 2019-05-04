#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <numeric>
#include <iostream>

using std::vector;
using std::cout;

class Solution
{
private:
    bool isSubsetSum(vector<int> &nums, int len, int sum) {
        if (sum == 0) {
            return true;
        }
        if (len == 0 && sum != 0) {
            return false;
        }

        return isSubsetSum(nums, len - 1, sum) || isSubsetSum(nums, len - 1, sum - nums[len - 1]);
    }
public:
    /*
     * 使用最直观的递归
     */
    bool canPartitionRecursive(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int n = nums.size();
        return isSubsetSum(nums, n - 1, sum >> 1) || isSubsetSum(nums, n - 1, (sum >> 1) - nums[n - 1]);
    }

    /*
     * 使用 DP, bottom up 会使用更多的 space.
     */
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) return false;

        int half = sum >> 1;
        int len = nums.size();
        int i, j;

        bool dp[half + 1][len + 1];

        for (i = 0; i < half + 1; ++i) {
            dp[i][0] = false;
        }
        for (j = 0; j < len + 1; ++j) {
            dp[0][j] = true;
        }

        for (i = 1; i < half + 1; ++i) {
            for (j = 1; j < len + 1; ++j) {
                // 根据递归中的递归式来写该式子就可。
                if (i - nums[j - 1] >= 0) {
                    dp[i][j] = dp[i][j - 1] || dp[i - nums[j - 1]][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        for (int j = 0; j < half + 1; ++j) {
            for (int i = 0; i < len + 1; ++i) {
               cout << (dp[j][i] ? "T" : "F") << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

        return dp[half][len];
    }

    // Using DP TOP-down approach.
    bool canPartitionTopDown(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int half = sum >> 1;
        bool dp[half + 1];
        int i;
        for (i = 0; i < half + 1; ++i) {
            dp[i] = false;
        }

        dp[0] = true;

        for (auto num: nums) {
            for (i = half; i > 0; --i) {
                if (i >= num) {
                    dp[i] = dp[i] || dp[i - num];
                }
            }
        }

        return dp[half];
    }
};

#endif
