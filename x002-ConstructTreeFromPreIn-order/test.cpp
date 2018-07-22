#include "gtest/gtest.h"
#include "solution.h"
#include <iostream>

using Tree = struct node *;

TEST(BuildTree, Empty) {
    string preStr = "ABDECF";
    string inStr = "DBEAFC";

    Solution s;

    Tree tree = s.buildTree(preStr, inStr, 0, 5);
    EXPECT_EQ(tree->data, 'A');

    string newPreStr;
    s.preOrderWalk(tree, newPreStr);
    EXPECT_EQ(preStr, newPreStr); 
    std::cout << newPreStr << std::endl;

    string newInStr;
    s.inOrderWalk(tree, newInStr);
    EXPECT_EQ(inStr, newInStr);
    std::cout << newInStr << std::endl;

    string postStr;
    s.postOrderWalk(tree, postStr);
    EXPECT_EQ(postStr, "DEBFCA");
    std::cout << postStr << std::endl;
}
