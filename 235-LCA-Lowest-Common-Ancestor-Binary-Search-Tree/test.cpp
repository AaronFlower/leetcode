#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <vector>

using std::vector;
using testing::ElementsAre;

TEST(LCA, CreateBinaryTree) {
    Solution s;
    TreeNode *root;
    vector<int> nums{6,2,8,0,4,7,9,-1,-1,3,5}, res;
    root = s.createBinaryTree(nums);
    res = s.BFSTraverse(root);
    EXPECT_THAT(res, ElementsAre(6,2,8,0,4,7,9,3,5));

    nums = {6, -1, 8};
    root = s.createBinaryTree(nums);
    res = s.BFSTraverse(root);
    EXPECT_THAT(res, ElementsAre(6, 8));
}


TEST(LCA, Serach) {
    Solution s;
    TreeNode *root, *node;
    vector<int> nums{6,2,8,0,4,7,9,-1,-1,3,5}, res;
    root = s.createBinaryTree(nums);

    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(8);
    node = s.lowestCommonAncestor(root, p, q);
    EXPECT_EQ(node->val, 6);
}
