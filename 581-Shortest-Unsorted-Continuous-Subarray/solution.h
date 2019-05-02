#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <string>
#include <vector>


using std::string;
using std::vector;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;

        int i = 1, j = len - 2;
        while (nums[i-1] <= nums[i] && i < len) ++i;

        if (i >= len) return 0;

        while (nums[j+1] >= nums[j] && j >= 0) --j;

        int min = nums[i], max = nums[i];
        for (int k = i; k <= j; ++k) {
            min = nums[k] < min ? nums[k] : min;
            max = nums[k] > max ? nums[k] : max;
        }

        i = 0, j = len - 1;
        while (nums[i] <= min) ++i;
        while (nums[j] >= max) --j;
        return j - i + 1;
    }
};

#endif
