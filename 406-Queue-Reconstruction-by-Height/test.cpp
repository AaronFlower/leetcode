#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

TEST(QueueReconstruction, Cmp) {
    Solution s;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    auto res = s.reconstructQueue(people);

    for (auto p : res) {
        std::cout << p[0] << ", " << p[1] << std::endl;
    }
}
