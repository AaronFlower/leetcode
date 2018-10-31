#ifndef LEET_CODE_TRIE__
#define LEET_CODE_TRIE__ 

#include <vector>
#include <string>

# define ALPHABET_SIZE 26

using std::vector;
using std::string;

struct Node {
    struct Node* children[ALPHABET_SIZE];
    bool isEnd;
    Node () {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    Node* root = nullptr;

    Trie(const vector<string> &keys) {
        if (!keys.empty()) {
            root = new Node();
            for (auto key : keys) {
                insert(key);
            }
        }
    }

    void insert(const string &key) {
        Node *pCrawl = root;
        for (char c: key) {
            int i = c - 'a';
            if (!pCrawl->children[i]) {
                pCrawl->children[i] = new Node();
            }
            pCrawl = pCrawl->children[i];
        }
        pCrawl->isEnd = true;
    }

    bool deleteKey(const string& key) {
        if (key.length()) {
            return deleteHelper(root, key);
        }
        return false;
    }

    bool deleteHelper(Node *root, const string& key) {
        if (root) {
            // Base case
            if (key.size() == 0) {
                if (root->isEnd) {
                    root->isEnd = false; // unmark the node
                    return hasNoChildren(root);
                }
                return false;
            } else {
                int i = key[0] - 'a';
                if (deleteHelper(root->children[i], key.substr(1))) {
                    delete root->children[i];
                    root->children[i] = nullptr;
                    // recursively climb up, and delete elligible nodes.
                    return !root->isEnd && hasNoChildren(root);
                }
            }
        }
        return false;
    }

    bool search(const string &key) {
        Node *pCrawl = root;
        for (char c:key) {
            int i = c - 'a';
            if (!pCrawl->children[i]) return false;
            pCrawl = pCrawl->children[i];
        }
        return pCrawl && pCrawl->isEnd;
    }

    ~Trie() {
        destroy(root);
    }

private:
    void destroy(Node *root) {
        if (root) {
            for (auto child : root->children) {
                destroy(child);
            }
            delete root;
        }
    }

    bool hasNoChildren(const Node* node) {
        for (Node *child: node->children) {
            if (child) return false;
        }
        return true;
    }

};
#endif /* ifndef LEET_CODE_TRIE__ */
