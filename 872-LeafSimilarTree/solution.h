#ifndef SOLUTION_H__
#define SOLUTION_H__

#include <vector>
#include <stack>
#include <queue>

using std::vector;
using std::stack;
using std::queue;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        TreeNode * createTree(vector<int> data) {
            if (data.empty()) return nullptr;
            TreeNode *root = new TreeNode(data[0]);
            TreeNode *cur;
            queue<TreeNode *> q;
            q.push(root);

            std::size_t i = 1;
            while (i < data.size()) {
                cur = q.front();
                if (data[i] != -1) {
                    cur->left = new TreeNode(data[i]);
                    q.push(cur->left);
                }
                if (data[i + 1] != -1) {
                    cur->right = new TreeNode(data[i + 1]);
                    q.push(cur->right);
                }
                i += 2;
            }

            return root;
        }

        vector<int> preOrderTraverse(TreeNode * root) {
            vector<int> data;
            TreeNode * cur = root;
            stack<TreeNode *> s;
            while (cur || !s.empty()) {
               while (cur) {
                   data.push_back(cur->val);
                   s.push(cur);
                   cur = cur->left;
               } 
               cur = s.top();
               s.pop();
               cur = cur->right;
            } 
            return data;
        }
};

#endif /* ifndef SOLUTION_H__ */
