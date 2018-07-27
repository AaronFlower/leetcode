#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

using testing::ElementsAre;

TEST(Tree, createTree) {
    Solution s;
    EXPECT_EQ(nullptr, s.createTree({}));

    TreeNode *t1;
    t1 = s.createTree({1, 2, 3, 4, 5});
    EXPECT_THAT(s.preOrderTraverse(t1), ElementsAre(1, 2, 4, 5, 3));
}
