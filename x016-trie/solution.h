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

};
#endif /* ifndef LEET_CODE_TRIE__ */
