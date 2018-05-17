#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <vector>
#include <iostream>
#include <string>


using std::vector;
using std::string;


TEST(Solution, addOperators) {
    Solution s;
    vector<int> originSet{3, 34, 4, 12, 5, 2};
    int sum;

    EXPECT_EQ(s.checkIsSubsetSumRecursion(originSet, originSet.size(), 9), true);

    originSet = {1, 8, 2, 5};
    sum = 4;
    EXPECT_EQ(s.checkIsSubsetSumRecursion(originSet, originSet.size(), sum), false);


    originSet = {1, 5, 11, 6};
    sum = 42;
    EXPECT_EQ(s.checkIsSubsetSumRecursion(originSet, originSet.size(), sum), false);
    
    originSet = {1, 3};
    sum = 4;
    EXPECT_EQ(s.checkIsSubsetSumRecursion(originSet, originSet.size(), sum), true);
}

TEST(Solution, addOperatorsMem) {
    Solution s;
    vector<int> originSet{3, 34, 4, 12, 5, 2};
    int sum;
    Solution::umap map;
    EXPECT_EQ(s.checkIsSubsetSumMem(originSet, originSet.size(), 9, map), true);

    originSet = {1, 8, 2, 5};
    map.clear();
    sum = 4;
    EXPECT_EQ(s.checkIsSubsetSumMem(originSet, originSet.size(), sum, map), false);


    originSet = {1, 5, 11, 6};
    map.clear();
    sum = 42;
    EXPECT_EQ(s.checkIsSubsetSumMem(originSet, originSet.size(), sum, map), false);
    
    originSet = {1, 3};
    map.clear();
    sum = 4;
    EXPECT_EQ(s.checkIsSubsetSumMem(originSet, originSet.size(), sum, map), true);
}

TEST(Solution, addOperatorsDP) {
    Solution s;
    vector<int> originSet{3, 34, 4, 12, 5, 2};
    int sum;
    EXPECT_EQ(s.checkIsSubsetSum(originSet, originSet.size(), 9), true);

    originSet = {1, 8, 2, 5};
    sum = 4;
    EXPECT_EQ(s.checkIsSubsetSum(originSet, originSet.size(), sum), false);


    originSet = {1, 5, 11, 6};
    sum = 42;
    EXPECT_EQ(s.checkIsSubsetSum(originSet, originSet.size(), sum), false);
    
    originSet = {1, 2};
    sum = 3;
    EXPECT_EQ(s.checkIsSubsetSum(originSet, originSet.size(), sum), true);
}
