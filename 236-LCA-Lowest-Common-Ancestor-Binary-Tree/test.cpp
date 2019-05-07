#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <vector>

using std::vector;
using testing::ElementsAre;

TEST(LCA, CreateBinaryTree) {
    Solution s;
    TreeNode *root;
    vector<int> nums{3,5,1,6,2,0,8,-1,-1,7,4}, res;
    root = s.createBinaryTree(nums);
    res = s.BFSTraverse(root);
    EXPECT_THAT(res, ElementsAre(3,5,1,6,2,0,8,7,4));

    nums = {6, -1, 8};
    root = s.createBinaryTree(nums);
    res = s.BFSTraverse(root);
    EXPECT_THAT(res, ElementsAre(6, 8));
}


TEST(LCA, Serach) {
    Solution s;
    TreeNode *root, *node;
    vector<int> nums{3,5,1,6,2,0,8,-1,-1,7,4}, res;
    root = s.createBinaryTree(nums);

    TreeNode *p = new TreeNode(5);
    TreeNode *q = new TreeNode(1);
    node = s.lowestCommonAncestor(root, p, q);
    EXPECT_EQ(node->val, 3);

    TreeNode *p1 = new TreeNode(5);
    TreeNode *q1 = new TreeNode(4);
    node = s.lowestCommonAncestor(root, p1, q1);
    EXPECT_EQ(node->val, 5);
}
