#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using testing::ElementsAre;

TEST(Solution, DiameterPassRoot) {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    treeNode *tree = s.createTree(nums);

    EXPECT_THAT(s.preOrder(tree), ElementsAre(1, 2, 4, 5, 3));
    EXPECT_THAT(s.inOrder(tree), ElementsAre(4, 2, 5, 1, 3));

    EXPECT_EQ(s.diameterOfTree(tree), 3);

    s.destroyTree(tree);

    nums = {};
    tree = s.createTree(nums);
    EXPECT_EQ(s.diameterOfTree(tree), 0);
    s.destroyTree(tree);


    nums = {1};
    tree = s.createTree(nums);
    EXPECT_EQ(s.diameterOfTree(tree), 0);
    s.destroyTree(tree);

    nums = {1, 2, 3, 4};
    tree = s.createTree(nums);
    EXPECT_EQ(s.diameterOfTree(tree), 3);
    s.destroyTree(tree);
}

TEST(Solution, DiamterNotPassRoot) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, -1, -1, 6, 7, 8, 9, 10, 11, -1, -1, 12, 13, -1, -1, 14};
    treeNode *tree = s.createTree(nums);

    EXPECT_EQ(s.diameterOfTree(tree), 7);
    s.destroyTree(tree);
}
