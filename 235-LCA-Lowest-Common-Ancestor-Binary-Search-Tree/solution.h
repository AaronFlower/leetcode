#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <queue>
using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return root;
        }

        if (root->val == q->val || root->val == p->val) {
            return root;
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }

    TreeNode* createBinaryTree(vector<int> &nums) {
        if (nums.empty() && nums[0] != -1) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(nums[0]);
        TreeNode *first;
        queue<TreeNode*> q;
        q.push(root);

        size_t i = 0;

        while (!q.empty() && i + 1 < nums.size()) {
           first = q.front();
           q.pop();
           if (nums[i + 1] != -1) {
               first->left = new TreeNode(nums[i + 1]);
               q.push(first->left);
           }
           if (nums[i + 2] != -1) {
               first->right = new TreeNode(nums[i + 2]);
               q.push(first->right);
           }
           i += 2;
        }
        return root;
    }

    vector<int> BFSTraverse(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        TreeNode *first;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            first = q.front();
            q.pop();
            res.push_back(first->val);
            if (first->left) {
                q.push(first->left);
            }
            if (first->right) {
                q.push(first->right);
            }
        }
        return res;
    }
};
#endif
