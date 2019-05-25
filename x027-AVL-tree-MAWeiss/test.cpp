#include "gtest/gtest.h"
#include "solution.h"

using std::cout;

TEST(AVLTree, ADT) {
    avlTree t;

    EXPECT_EQ(t.find(1), nullptr);
    EXPECT_EQ(t.findMax(), nullptr);
    EXPECT_EQ(t.findMin(), nullptr);

    t.insert(6);
    EXPECT_EQ(t.findMax()->val, 6);
    EXPECT_EQ(t.findMin()->val, 6);

    t.insert(2);
    t.insert(8);
    t.insert(1);
    t.insert(4);
    t.insert(3);
    auto res = t.printTree();

    EXPECT_EQ(res.size(), 6);
    for (auto record : res) {
        std::cout << record;
    }
}

TEST(AVLTree, insert) {
    avlTree t;

    vector<int> nums {5, 2, 8, 1, 4};
    for (int n : nums) {
        t.insert(n);
    }
    auto res = t.printTree();
    for (auto record : res) {
        std::cout << record;
    }
    EXPECT_EQ(t.height(), 2);

    // insert 3, we need doule rotate
    cout << "After insert 3 \n";

    t.insert(3);
    res = t.printTree();
    for (auto record : res) {
        std::cout << record;
    }
    EXPECT_EQ(t.height(), 2);

    nums = {10, 13, 16, 14};
    for (int n : nums) {
        t.insert(n);
    }

    cout << "After insert 10, 13, 16, 14 \n";

    res = t.printTree();
    for (auto record : res) {
        std::cout << record;
    }
    EXPECT_EQ(t.height(), 3);
}
