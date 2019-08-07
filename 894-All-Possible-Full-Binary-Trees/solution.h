#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode *>  allPossibleFBT(int n) {
        vector<TreeNode *>  res;

        if (n == 1) {
            res.push_back(new TreeNode(0));
        } else if (n % 2) { // even nodes can't generate a FBT
            for (int i = 0; i < n; ++i) {
                auto left = allPossibleFBT(i);
                auto right = allPossibleFBT(n - 1 - i);
                for (auto lnode : left) {
                    for (auto rnode : right) {
                        auto root = new TreeNode(0);
                        root->left = lnode;
                        root->right = rnode;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> traverseAllTrees(vector<TreeNode *>& trees) {
        vector<vector<int>> vvi;
        for (auto tree : trees) {
            vvi.push_back(traverse(tree));
        }
        return vvi;
    }

private:
    vector<int> traverse(TreeNode* &root) {
        vector<int> res;
        if (!root) return res;

        TreeNode* cur;
        queue<TreeNode* > q;
        q.push(root);

        while (!q.empty()) {
            std::size_t len = q.size();
            for (std::size_t i = 0; i < len; ++i) {
                cur = q.front();
                q.pop();
                res.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    if (!cur->left) {
                        res.push_back(-1);
                    }
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};
