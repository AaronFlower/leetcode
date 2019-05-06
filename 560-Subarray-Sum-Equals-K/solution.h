#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <numeric>
#include <unordered_map>

using std::vector;
using std::accumulate;
using std::unordered_map;

class Solution {
public:
    int subarraySumBrutalForce(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        int s[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j)
                    s[i][j] = nums[j];
                else
                    s[i][j] = s[i][j - 1] + nums[j];
                if (s[i][j] == k)
                    ++count;
            }
        }
        return count;
    }

    int subarraySum2(vector<int> &nums, int k) {
        int count = 0, len = nums.size(), i, j;

        for (i = 1; i < len; ++i) {
            nums[i] += nums[i - 1];
        }

        for (i = 0; i < len; ++i) {
            if (nums[i] == k) ++count;
            for (j = i + 1; j < len; ++j) {
                if (nums[j] - nums[i] == k) ++count;
            }
        }
        return count;
    }

    int subarraySumMap(vector<int> &nums, int k) {
        int len = nums.size();
        int accSum = 0, count = 0;
        unordered_map<int, int> map;

        map[0] = 1;
        for (int i = 0; i < len; ++i) {
            accSum += nums[i];
            if (map[accSum - k]) {
                count += map[accSum - k];
            }
            map[accSum]++;
        }
        return count;
    }
};

#endif
