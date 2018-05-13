#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using testing::ElementsAre;

TEST(TwoSum, BruteForce) {
    Solution s;
    vector<int> nums, res;
    nums = {1, 2, 3, 5}; 
    res = s.twoSumBruteForce(nums, 6);
    EXPECT_THAT(res, ElementsAre(0, 3));
    
    nums = {2, 7, 11, 15}; 
    res = s.twoSumBruteForce(nums, 9);
    EXPECT_THAT(res, ElementsAre(0, 1));

    nums = {3,2,4}; 
    res = s.twoSumBruteForce(nums, 6);
    EXPECT_THAT(res, ElementsAre(1, 2));

    nums = {2, 7, 11, 15}; 
    res = s.twoSumBruteForce(nums, 19);
    EXPECT_THAT(res, ElementsAre());
}

TEST(TwoSum, HashMapTwiceLoop) {
    Solution s;
    vector<int> nums, res;
    nums = {1, 2, 3, 5}; 
    res = s.twoSumTwiceLoop(nums, 6);
    EXPECT_THAT(res, ElementsAre(0, 3));
    
    nums = {2, 7, 11, 15}; 
    res = s.twoSumTwiceLoop(nums, 9);
    EXPECT_THAT(res, ElementsAre(0, 1));

    nums = {3,2,4}; 
    res = s.twoSumTwiceLoop(nums, 6);
    EXPECT_THAT(res, ElementsAre(1, 2));

    nums = {2, 7, 11, 15}; 
    res = s.twoSumTwiceLoop(nums, 19);
    EXPECT_THAT(res, ElementsAre());
}

TEST(TwoSum, HashMap) {
    Solution s;
    vector<int> nums, res;
    nums = {1, 2, 3, 5}; 
    res = s.twoSum(nums, 6);
    EXPECT_THAT(res, ElementsAre(0, 3));
    
    nums = {2, 7, 11, 15}; 
    res = s.twoSum(nums, 9);
    EXPECT_THAT(res, ElementsAre(0, 1));

    nums = {3,2,4}; 
    res = s.twoSum(nums, 6);
    EXPECT_THAT(res, ElementsAre(1, 2));

    nums = {2, 7, 11, 15}; 
    res = s.twoSum(nums, 19);
    EXPECT_THAT(res, ElementsAre());
}
