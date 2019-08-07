#include <vector>
#include <queue>

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v):left(nullptr), right(nullptr), val(v) {}
};

using std::vector;
using std::queue;

class Solution {
public:
    vector<TreeNode*> generateAllTrees(int N) {
        return genAll(1, N);
    }

    vector<int> traverse(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> q;

        if (!root) return res;

        q.push(root);
        TreeNode* cur;

        while(!q.empty()) {
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

private:
    /**
     * Simple Recursive Implementation, but will create Frikenstain tree.
     */
    vector<TreeNode* > genAll(int start, int end) {
        vector<TreeNode *> trees;
        if (start > end) {
            trees.push_back(nullptr);
        } else {
            for (int i = start; i <= end; ++i) {
                auto left = genAll(start, i - 1);
                auto right = genAll(i + 1, end);

                for (auto lnode : left) {
                    for (auto rnode : right) {
                        auto root = new TreeNode(i);
                        root->left = lnode;
                        root->right = rnode;
                        trees.push_back(root);
                    }
                }
            }
        }

        return trees;
    }
};
