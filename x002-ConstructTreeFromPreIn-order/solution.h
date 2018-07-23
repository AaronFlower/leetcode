#ifndef X002_SOLUTION_H__
#define X002_SOLUTION_H__

#include <string>

using std::string;

struct node {
    char data;
    struct node * left;
    struct node * right;
    node (char v):data(v), left(nullptr), right(nullptr){}
};


class Solution {
    public:
        using treeNode = struct node;

        treeNode* buildTreePreIn(const string &preStr, const string &inStr, int start, int end) {
            static int preIndex; 
            if (start > end) return nullptr;
            
            char ch = preStr[preIndex++];
            treeNode* node = new treeNode(ch);
           
            if (start == end) return node;

            int inIndex = inStr.find(ch);
            assert(inIndex != std::string::npos);
            node->left = buildTreePreIn(preStr, inStr, start, inIndex - 1);
            node->right = buildTreePreIn(preStr, inStr, inIndex + 1, end);
            return node;
        } 

        treeNode* buildTreePostIn(const string &postStr, const string &inStr, int start, int end) {
            static int postIndex = end;
            if (start > end) return nullptr;
            
            char ch = postStr[postIndex--];
            treeNode *node = new treeNode(ch);
            if (start == end) return node;

            int index = inStr.find(ch);
            assert(index != std::string::npos);
            node->right = buildTreePostIn(postStr, inStr, index + 1, end);
            node->left = buildTreePostIn(postStr, inStr, start, index - 1);
            return node;
        }

        void preOrderWalk (treeNode *tree, string &str) {
            if (tree) {
                str.append({tree->data});
                preOrderWalk(tree->left, str);
                preOrderWalk(tree->right, str);
            }
        } 

       void inOrderWalk (treeNode *tree, string &str) {
           if (tree) {
               inOrderWalk(tree->left, str);
               str.append(1, tree->data);
               inOrderWalk(tree->right, str);
           }
       }
       
       void postOrderWalk (treeNode *tree, string &str) {
            if (tree) {
                postOrderWalk(tree->left, str);
                postOrderWalk(tree->right, str);
                str.append({tree->data});
            }
        } 

};
#endif /* ifndef SYMBOLX002_SOLUTION_H__ */
