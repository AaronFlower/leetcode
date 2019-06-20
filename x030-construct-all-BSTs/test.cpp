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


TEST(Solution, unique_orderings) {
    Solution s;
    auto ret = s.unique_orderings(1, 2);

    for (auto row :ret) {
        std::cout << "[" ;
        for (auto n: row) {
            std::cout << n << "\t";
        }
        std::cout << "]" << std::endl;
    }

    vector<int> nums;
    nums.emplace_back();
    nums.emplace_back();
    nums.emplace_back(13);
    nums.emplace_back(1);

    std::cout << "emplace_back " << std::endl;
    for (auto n : nums) {
        std::cout << n << std::endl;
    }

    std::cout << "vvi : " << std::endl;
    vector<vector<int>> viret;
    viret.emplace_back();
    viret.emplace_back(3);
    viret.emplace_back(1, 2);
    viret.emplace_back(4, 5);
    viret.emplace_back(3, 6);
    int i = 0;

    for (auto row : viret) {
        std::cout << ++i << std::endl;
        for (auto n : row) {
            std::cout << "\t " << n << std::endl;
        }
    }

}
