#include "gtest/gtest.h"
#include "solution.h"


TEST(Solution, Knapsack01) {
    Solution s;
    int vals[] = {7, 8, 4};
    int weights[] = {3, 8, 6};
    EXPECT_EQ(s.knapSack(vals, weights, 3, 10), 11);

    std::cout << std::endl;
    int vals1[] =  {10, 40, 30, 50};
    int weights1[] = {5, 4, 6, 3};
    EXPECT_EQ(s.knapSack(vals1, weights1, 4, 10), 90);
}
