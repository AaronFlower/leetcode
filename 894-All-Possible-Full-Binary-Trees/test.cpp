#include "gtest/gtest.h"
#include "solution.h"

TEST(FBT, create) {
    Solution s;

    auto trees = s.allPossibleFBT(7);
    auto vvi = s.traverseAllTrees(trees);

    for (auto vi : vvi) {
        std::cout << "[";
        for (auto n : vi) {
            if (n == -1) {
                std::cout << "null" << "\t";
            } else {
                std::cout << n << "\t";
            }
        }
        std::cout << "]" << std::endl;
    }

}
