#ifndef AVL_SEARCH_TREE__
#define AVL_SEARCH_TREE__

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using std::max;
using std::vector;
using std::string;
using std::stringstream;

typedef int elementType;

typedef struct treeNode {
    elementType val;
    int height;
    treeNode *left;
    treeNode *right;

    treeNode():val(0), height(0), left(nullptr), right(nullptr){}
    treeNode(int v):val(v), height(0), left(nullptr), right(nullptr){}
} treeNode, *position;

class avlTree {
public:
    avlTree():root(nullptr){}
    ~avlTree() {
        destroy(root);
    }

    position findMin() {
        if (!root) return nullptr;
        return findMin(root);
    }

    position findMax() {
        if (!root) return nullptr;
        return findMax(root);
    }

    position find(elementType x) {
        return find(root, x);
    }

    vector<string> printTree() {
        vector<string> res;
        print(root, res, 0);
        return res;
    }

    void insert(elementType x) {
        root = insertHelper(root, x);
    }

    int height () {
        return height(root);
    }

private:
    treeNode *root;

    void destroy (treeNode *node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    treeNode *insertHelper(treeNode *node, elementType x) {
        if (!node) {
            node = new treeNode(x);
            return node;
        } else if (node->val < x) {
            node->right = insertHelper(node->right, x);
            if (height(node->right) - height(node->left) == 2) {
                if (node->right->val < x) {
                    // right - right
                    node = singleRotateWithRight(node);
                } else {
                    node = doubleRotateWithRight(node);
                }
            }
        } else if (node->val > x) {
            node->left = insertHelper(node->left, x);
            if (height(node->left) - height(node->right) == 2) {
                if (node->left->val > x) {
                    node = singleRotateWithLeft(node);
                } else {
                    node = doubleRotateWithLeft(node);
                }
            }
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        return node;
    }

    int height(treeNode *node) {
        if (!node) return -1;
        return node->height;
    }


    position findMin(treeNode *node) {
        if (!node->left) return node;
        return findMin(node->left);
    }

    position findMax(treeNode *node) {
        if (!node->right) return node;
        return findMin(node->right);
    }

    position find(treeNode *node, elementType x) {
        if (!node) {
            return nullptr;
        } else if (node->val < x) {
            return find(node->right, x);
        } else if (node->val > x) {
            return find(node->left, x);
        }
        return node;
    }

    void print(treeNode *node, vector<string> &res, int depth) {
        if (!node) return;
        string pad(depth * 4, '~');
        stringstream str;
        str << "|" << pad << node->val << "\n";
        res.push_back(str.str());
        print(node->left, res, depth + 1);
        print(node->right, res, depth + 1);
    }

    /**
     * single rotate: left -> left
     */
    treeNode * singleRotateWithLeft(treeNode *node) {
        assert(node != nullptr);
        treeNode *k1 = node, *k2 = node->left;

        k1->left = k2->right;
        k2->right = k1;

        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        return k2;
    }

    /**
     * single rotate: right->right
     */
    treeNode * singleRotateWithRight(treeNode *node) {
        assert(node != nullptr);
        treeNode *k1 = node, *k2 = node->right;

        k1->right = k2->left;
        k2->left = k1;

        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        return k2;
    }

    /**
     * double rotate: left - right
     */
    treeNode * doubleRotateWithLeft(treeNode *node) {
        node->left = singleRotateWithRight(node->left);
        return singleRotateWithLeft(node);
    }

    /**
     * double rotate: right - left
     */
    treeNode * doubleRotateWithRight(treeNode *node) {
        node->right = singleRotateWithLeft(node->right);
        return singleRotateWithLeft(node);
    }

};

#endif /* ifndef AVL_SEARCH_TREE__ */
