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

/* private: */
    /**
     * 使用这种方法创建，会共享创建的分支。对于释放内存时来说是一个很困难的事情。
     * 即我们创建一个 Frankenstein 树。这是我们要避免的。
     */
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

    vector<vector<int>> unique_orders(int start, int end) {
        vector<vector<int>> list;
        if (start > end) {
            list.push_back({});
            return list;
        }

        for (int i = start; i <= end; ++i) {
            auto left_orders = unique_orders(start, i - 1);
            auto right_orders = unique_orders(i + 1, end);

            for (int j = 0; j < (int)left_orders.size(); ++j) {
            }
        }
        return list;
    }

    vector<vector<int>> unique_orderings(int first, int last) {
        vector<vector<int>> ret;
        if (first == last) {
          ret.emplace_back();
        } else {
          // For each possible root digit
          for (int digit = first; digit != last; ++digit) {

            // Get all the orderings to build unique left branches
            auto left_orders = unique_orderings(first, digit);

            // Get all the orderings to build unique right branches
            auto right_orders = unique_orderings(digit + 1, last);

            // Combine all the possibilities together
            for (auto& left : left_orders) {
              for (auto& right : right_orders) {
                ret.emplace_back(1, digit);
                ret.reserve(left.size() + 1 + right.size());
                std::copy(left.begin(), left.end(), std::back_inserter(ret.back()));
                std::copy(right.begin(), right.end(), std::back_inserter(ret.back()));
              }
            }
          }
        }
        return ret;
    }
};
#endif
