#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::make_pair;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            auto ret = map.find(target - nums[i]);
            if (ret != map.cend()) {
                return {ret->second, i};
            } else {
                map.insert(make_pair(nums[i], i));
            }
        }

        return {};
    }

    vector<int> twoSumTwiceLoop(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            map.insert(make_pair(nums[i], i));
        }
        
        for (int i = 0; i < len; ++i) {
            auto ret = map.find(target - nums[i]);
            if (ret != map.cend() && i != ret->second) {
                return {i, ret->second};
            }
        }

        return {};
    }

    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        } 
        return {};
    }
};

#endif
