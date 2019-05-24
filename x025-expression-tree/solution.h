#ifndef EXPRESSION_TREE__
#define EXPRESSION_TREE__

#include <string>
#include <stack>

using std::string;
using std::stack;

typedef struct treeNode {
    char val;
    treeNode * left;
    treeNode * right;
    treeNode (char c):val(c), left(nullptr), right(nullptr){}
} treeNode;

class tree {
public:
    tree():root(nullptr){}

    /**
     * create a by suffix expression str.
     * e.g ab+cde+**
     */
    tree(const string &sufixStr):root(nullptr) {
        if (sufixStr.empty()) return;
        stack<treeNode *> s;
        treeNode *node, *top;

        for (char c : sufixStr) {
            node = new treeNode(c);
            if (!isalpha(c)) {
                if (!s.empty()) {
                    top = s.top();
                    s.pop();
                    node->right = top;
                }
                if (!s.empty()) {
                    top = s.top();
                    s.pop();
                    node->left = top;
                }
            }
            s.push(node);
        }
        root = s.top();
        s.pop();
    }

    ~tree() {
        destroyTree(root);
    }

    string preOrder() {
        string s;
        preOrderHelper(root, s);
        return s;
    }

    string preOrderS() {
        string str;
        treeNode *top, *node;
        if (!root) return str;

        stack<treeNode *> s;
        s.push(root);

        while (!s.empty()) {
            node = s.top();
            while (node) {
                str += node->val;
                node = node->left;
                if (node) s.push(node);
            }

            while (!s.empty()) {
                top = s.top();
                s.pop();
                if (top->right) {
                    s.push(top->right);
                    break;
                }
            }
        }
        return str;
    }

    string inOrder() {
        string s;
        inOrderHelper(root, s);
        return s;
    }

    string postOrder() {
        string s;
        postOrderHelper(root, s);
        return s;
    }

private:
    treeNode *root;

    void destroyTree(treeNode *root) {
        if (root) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

    void preOrderHelper(treeNode *node, string &s) {
        if (node) {
            s += node->val;
            preOrderHelper(node->left, s);
            preOrderHelper(node->right, s);
        }
    }

    void inOrderHelper(treeNode *node, string &s) {
        if (node) {
            inOrderHelper(node->left, s);
            s += node->val;
            inOrderHelper(node->right, s);
        }
    }

    void postOrderHelper(treeNode *node, string &s) {
        if (node) {
            postOrderHelper(node->left, s);
            postOrderHelper(node->right, s);
            s += node->val;
        }
    }
};

#endif
