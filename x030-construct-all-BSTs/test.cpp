#include "gtest/gtest.h"
#include "solution.h"

#include <iostream>

TEST(Solution, Nodes0) {
    Solution s;
    vector<node *> trees = s.constructAllBST(0);
    vector<int> nums;

    for (auto tree: trees) {
        nums = s.preorder(tree);
        for (auto n:nums) {
            std::cout << n << "\t";
        }
        std::cout << "\n";
    }
}

TEST(Solution, Nodes1) {
    Solution s;
    vector<node *> trees = s.constructAllBST(1);
    vector<int> nums;

    for (auto tree: trees) {
        nums = s.preorder(tree);
        for (auto n:nums) {
            std::cout << n << "\t";
        }
        std::cout << "\n";
    }
}

TEST(Solution, Nodes2) {
    Solution s;
    vector<node *> trees = s.constructAllBST(2);
    vector<int> nums;

    for (auto tree: trees) {
        nums = s.preorder(tree);
        for (auto n:nums) {
            std::cout << n << "\t";
        }
        std::cout << "\n";
    }
}



TEST(Solution, ConstructAllBSTs) {
    Solution s;

    vector<node *> trees = s.constructAllBST(3);
    vector<int> nums;

    for (auto &tree : trees) {
        nums = {};
        s.pre(tree, nums);
        for (auto n : nums) {
            std::cout << n << "\t";
        }
        std::cout << "\n";
    }
}
