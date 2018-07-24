#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "solution.h"

using testing::ElementsAre;

TEST(Tree, ConstructTree) {
    vector<int> tree1Data{1, 3, 2, 5};
    vector<int> tree2Data{2, 1, 3, -1, 4, -1, 7};

    Solution s;

    EXPECT_EQ(nullptr, s.createTree({}));
    
    TreeNode * t1 = s.createTree(tree1Data);

    EXPECT_THAT(s.inOrderTraverse(t1), ElementsAre(5, 3, 1, 2)); 
    EXPECT_THAT(s.preOrderTraverse(t1), ElementsAre(1, 3, 5, 2)); 

    TreeNode *t2 = s.createTree(tree2Data);

    EXPECT_THAT(s.inOrderTraverse(t2), ElementsAre(1, 4, 2, 3, 7)); 
    EXPECT_THAT(s.preOrderTraverse(t2), ElementsAre(2, 1, 4, 3, 7)); 
}

TEST(Tree, MergeTwoTreesRecursive) {
    vector<int> tree1Data{1, 3, 2, 5};
    vector<int> tree2Data{2, 1, 3, -1, 4, -1, 7};

    Solution s;
    TreeNode *t1 = s.createTree(tree1Data);
    TreeNode *t2 = s.createTree(tree2Data);

    TreeNode *t3 = s.mergeTwoTreesRecurisve(t1, t2);

    EXPECT_THAT(s.inOrderTraverse(t3), ElementsAre(5, 4, 4, 3, 5, 7)); 
    EXPECT_THAT(s.preOrderTraverse(t3), ElementsAre(3, 4, 5, 4, 5, 7)); 
}

