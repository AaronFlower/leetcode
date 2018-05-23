#include "gtest/gtest.h"
#include "solution.h"

TEST(LongestIncreasingSequence, DP) {
    Solution s;
    vector<int> t;

    t = {};
    EXPECT_EQ(s.lengthOfLIS(t), 0);

    t = {3, 2};
    EXPECT_EQ(s.lengthOfLIS(t), 1);

    t = {2, 3, 4};
    EXPECT_EQ(s.lengthOfLIS(t), 3);

    t = {2, 6, 5, 7, 4, 1, 8, 3};
    EXPECT_EQ(s.lengthOfLIS(t), 4);

    t = {10,9,2,5,3,7,101,18};
    EXPECT_EQ(s.lengthOfLIS(t), 4);
} 

TEST(LongestIncreasingSequence, STL) {
    Solution s;
    vector<int> t;

    t = {};
    EXPECT_EQ(s.lengthOfLisIt(t), 0);

    t = {3, 2};
    EXPECT_EQ(s.lengthOfLisIt(t), 1);

    t = {2, 3, 4};
    EXPECT_EQ(s.lengthOfLisIt(t), 3);

    t = {2, 6, 5, 7, 4, 1, 8, 3};
    EXPECT_EQ(s.lengthOfLisIt(t), 4);

    t = {10,9,2,5,3,7,101,18};
    EXPECT_EQ(s.lengthOfLisIt(t), 4);
} 


TEST(StdAlgo, lowerBound) {
    vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
    vector<int>::iterator it = std::lower_bound(data.begin(), data.end(), 1);
    std::cout << *it <<std::endl;
 
    vector<int>::iterator leftIt = std::lower_bound(data.begin(), data.end(), 3);
    vector<int>::iterator rightIt = std::upper_bound(data.begin(), data.end(), 3);
    while (leftIt < rightIt) {
        std::cout << *leftIt++ << "\t";
    }
    std::cout<<std::endl;
    
    // if left out of bound return the begin
    it = std::lower_bound(data.begin(), data.end(), 0);
    std::cout << *it << "Distance:" << data.end() - it <<std::endl;

    // if right out of bound return the end
    it = std::lower_bound(data.begin(), data.end(), 11);
    std::cout << *it << "Distance:" << data.end() - it <<std::endl;
    
    it = std::lower_bound(data.begin(), data.begin(), 1);
    std::cout << *it << "Distance:" << data.begin() - it <<std::endl;
}
