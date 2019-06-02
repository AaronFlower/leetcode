#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::max;

typedef struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int v):val(v), left(nullptr), right(nullptr){}
}treeNode;

class Solution {
public:

    /**
     * 计算树的直径，即树中两个节点最长的路径，这个路径可能经过根也可能不经过
     */
    int diameterOfTree(treeNode *root) {
        if (!root) return 0;

        int leftDiameter = diameterOfTree(root->left);
        int rightDiameter = diameterOfTree(root->right);

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    }

    int height(treeNode *root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }

    /**
     * 根据 vector 来创建二叉树，值为 -1 表示 null 节点。
     */
    treeNode *createTree(vector<int> &data) {
        if (data.empty() || data[0] == -1) return nullptr;

        treeNode *root = new treeNode(data[0]);
        int i = 1, len = data.size();
        queue<treeNode *> q;
        q.push(root);

        while (!q.empty() && i < len) {
            treeNode *node = q.front();
            q.pop();

            if (data[i] != -1) {
                node->left = new treeNode(data[i]);
                q.push(node->left);
            }

            ++i;

            if (i < len && data[i] != -1) {
                node->right = new treeNode(data[i]);
                q.push(node->right);
            }
            ++i;
        }
        return root;
    }

    vector<int> inOrder(treeNode *root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

    vector<int> preOrder(treeNode *root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }

    void destroyTree(treeNode *root) {
        if (root) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

private:

    void inOrder(treeNode *root, vector<int> &res) {
        if (!root) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    void preOrder(treeNode *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
};

#endif
