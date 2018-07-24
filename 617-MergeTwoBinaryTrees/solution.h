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
        TreeNode * createTree(vector<int> data) {
            if (data.size() == 0) return nullptr;
            assert(data[0] != -1);
            queue<TreeNode *> q;
            TreeNode *root = new TreeNode(data[0]);
            int index = 1;
            int len = data.size();
            q.push(root);
            
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                if (index < len && data[index] != -1) {
                    node->left = new TreeNode(data[index]);
                    q.push(node->left);
                }
                ++index;
                if (index < len && data[index] != -1) {
                    node->right = new TreeNode(data[index]);
                    q.push(node->right);
                }
                ++index;
            }

            return root;
        }

        TreeNode * mergeTwoTreesRecurisve (TreeNode *t1, TreeNode * t2) {
            if (!t1) return t2;
            if (!t2) return t1;
            
            t1->val += t2->val;
            t1->left = mergeTwoTreesRecurisve(t1->left, t2->left);
            t1->right = mergeTwoTreesRecurisve(t1->right, t2->right);
            return t1;
        }

        vector<int> inOrderTraverse(TreeNode *tree) {
            vector<int> data;
            inOrder(tree, data);
            return data;
        } 

        vector<int> preOrderTraverse(TreeNode *tree) {
            vector<int> data;
            preOrder(tree, data);
            return data;
        } 

    private:

        void inOrder(TreeNode *tree, vector<int> &data) {
            if (tree) {
                inOrder(tree->left, data);
                data.push_back(tree->val);
                inOrder(tree->right, data);
            }
        }

        void preOrder(TreeNode *tree, vector<int> &data) {
            if (tree) {
                data.push_back(tree->val);
                preOrder(tree->left, data);
                preOrder(tree->right, data);
            }
        }
};
#endif
