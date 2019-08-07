#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

vector<vector<int>> getNums(vector<TreeNode *> &trees) {
    Solution s;
    vector<vector<int>> vvi;
    for (auto tree : trees) {
        vvi.push_back(s.traverse(tree));
    }
    return vvi;
}

TEST(LinkList, create) {
    Solution s;
    vector<TreeNode *> trees = s.generateAllTrees(1);

    auto vvi = getNums(trees);
    for (auto vi : vvi) {
        std::cout << "[";
        for (auto n : vi) {
            if (n == -1) {
                std::cout << "null" << "\t";
            } else {
                std::cout << n << "\t";
            }
        }
        std::cout << "]\n\n";
    }


    /* trees = s.generateAllTrees(3); */
    trees = s.generateAllTrees(4);
    vvi = getNums(trees);
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
