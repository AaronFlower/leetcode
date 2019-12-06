//
// Created by eason on 2019/12/7.
//

#ifndef MY_HUFFMAN__
#define MY_HUFFMAN__


#include <iostream>
#include <vector>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::queue;
using std::priority_queue;
using std::string;

struct node {
    char data;
    int freq;
    node *left;
    node *right;
    node():data('-'),freq(0),left(nullptr),right(nullptr){}
    node(char c, int f):data(c),freq(f),left(nullptr),right(nullptr){}
};

typedef node tree;
typedef pair<char, int> freq;

class Huffman{
private:
    tree* root;
public:
    Huffman():root(nullptr){}
    void build(vector<freq> freqs) {
        if (freqs.empty()) return;
        auto cmp = [](node* f1, node* f2) {
            return f1->freq > f2->freq;
        };

        priority_queue<node*, vector<node*>, decltype(cmp)> q(cmp);

        for (freq f:freqs) {
            q.push(new node(f.first, f.second));
        }

        while (q.size() > 1) {
            node *r = new node;
            r->left = q.top();
            q.pop();
            r->right = q.top();
            q.pop();
            r->freq += r->left->freq + r->right->freq;
            q.push(r);
        }
        root = q.top();
        q.pop();
    }

    void printTree() {
        if (!root) return;
        queue<node*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            for (int i = 0, len = q.size(); i < len; ++i) {
                node* n = q.front();
                cout << string((level) * 4, ' ') << n->data << "(" << n->freq << ")" << endl;
                q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ++level;
        }
    }

    ~Huffman() {
        destroy(root);
    }

private:
    void destroy(tree* t) {
        if (t) {
            destroy(t->left);
            destroy(t->right);
            delete t;
        }
    }
};

#endif /* ifndef MY_HUFFMAN__ */
