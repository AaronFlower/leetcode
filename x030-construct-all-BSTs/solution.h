#ifndef LEET_ALL_BSTS__
#define LEET_ALL_BSTS__

#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct node {
    int val;
    node *left;
    node *right;
    node(int v):val(v), left(nullptr), right(nullptr){}
};

class Solution {

public:
    vector<node *> constructAllBST(int n) {
        return construct(1, n);
    }

    void pre(node *root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            pre(root->left, res);
            pre(root->right, res);
        }
    }

    vector<int> preorder(node *root) {
        vector<int> res;
        stack<node *> s;

        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                res.push_back(root->val);
                root = root->left;
            }

            root = s.top();
            s.pop();

            root = root->right;
        }

        return res;
    }

private:
    vector<node *> construct(int start, int end) {
        vector<node *> list;
        if (start > end) {
            list.push_back(nullptr);
            return list;
        }

        for (int i = start; i <= end; ++i) {
            vector<node *> leftList = construct(start, i - 1);
            vector<node *> rightList = construct(i + 1, end);

            for (int j = 0; j < (int)leftList.size(); ++j) {
                node *left = leftList[j];
                for (int k = 0; k < (int)rightList.size(); ++k) {
                    node *right = rightList[k];
                    node *root = new node(i);
                    root->left = left;
                    root->right = right;
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};
#endif
