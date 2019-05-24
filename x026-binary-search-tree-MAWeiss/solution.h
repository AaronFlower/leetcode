#ifndef BIANARY_SEARCH_TREE__
#define BIANARY_SEARCH_TREE__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

typedef int elementType;

typedef struct treeNode {
    elementType val;
    treeNode *left;
    treeNode *right;
    treeNode():val(0),left(nullptr), right(nullptr){}
    treeNode(int v):val(v),left(nullptr), right(nullptr) {}
} treeNode, *position;


class searchTree {
public:
    searchTree():root(nullptr){}
    ~searchTree() {
        destoryTree(root);
    }

    position find(elementType x) {
        return findHelper(root, x);
    }

    position findMin() {
        return findMinHelper(root);
    }

    position findMax() {
        return findMaxHelper(root);
    }

    void insertElement(elementType x) {
       insertHelper(root, x);
    }

    void deleteElement(elementType x) {
        deleteHelper(root, x);
    }

    vector<string> printTree() {
        vector<string> res;
        printHelper(root, 0, res);
        return res;
    }

private:
    treeNode *root;

    void destoryTree(treeNode *root) {
        if (root) {
            destoryTree(root->left);
            destoryTree(root->right);
            delete root;
        }
    }

    position findHelper(treeNode *node, elementType x) {
        if (!node) return nullptr;
        if (node->val > x) return findHelper(root->left, x);
        else if (node->val < x) return findHelper(root->right, x);
        else return node;
    }

    position findMinHelper(treeNode *node) {
        if (!node) {
            return nullptr;
        } else {
            if (!node->left) return node;
            return findMinHelper(node->left);
        }
    }

    position findMaxHelper(treeNode *node) {
        if (!node) {
            return nullptr;
        } else {
            if (!node->right) return node;
            return findMaxHelper(node->right);
        }
    }

    /*
     * insertHelper 函数可以使用下面使用返回值的方式来实现；
     * 在这里我们用引用来实现.
     */
    void insertHelper(treeNode *&node, elementType x) {
        if (!node) {
            node = new treeNode(x);
        } else if (node->val > x) {
            insertHelper(node->left, x);
        } else if (node->val < x) {
            insertHelper(node->right, x);;
        }
    }

    /* treeNode *insertHelper(treeNode *node, elementType x) { */
    /*     if (!node) { */
    /*         node = new treeNode(x); */
    /*     } else if (node->val > x) { */
    /*         node->left = insertHelper(node->left, x); */
    /*     } else if (node->val < x) { */
    /*         node->right = insertHelper(node->right, x);; */
    /*     } */
    /*     return node; */
    /* } */

    /**
     * 和其它数据结构一样，最麻烦的操作就是删除节点了。
     * 1. 如果是叶子节点则直接删除；
     * 2. 只有两个孩子，则用右子树的最小节点的值替换该值，然后去删除右子树的最小节点。
     *
     * 为了操作方便，删除函数是要有返回值的。
     */
    treeNode* deleteHelper(treeNode *node, elementType x) {
        treeNode *tmpNode;
        if (!node) return nullptr;

        if (node->val > x) {
            node->left = deleteHelper(node->left, x);
        } else if (node->val < x) {
            node->right = deleteHelper(node->right, x);
        }

        if (node->left && node->right) {
            position needle = findMin();
            node->val = needle->val;
            node->right = deleteHelper(node->right, needle->val);
        } else {
            tmpNode = node;
            if (node->left == nullptr) {
                node = node->right;
            } else {
                node = node->left;
            }
            delete tmpNode;
        }
        return node;
    }

    void printHelper(treeNode *node, int depth, vector<string> &res) {
        if (!node) return;
        string pad(depth * 4, '~');
        stringstream str;
        str << "|"<< pad << node->val << "\n";
        res.push_back(str.str());
        printHelper(node->left, depth + 1, res);
        printHelper(node->right, depth + 1, res);
    }
};

#endif /* ifndef BIANARY_SEARCH_TREE__ */
