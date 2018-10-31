#ifndef SOLUTION_H__
#define SOLUTION_H__

#define ALPHABET_SIZE 26

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Node {
    struct Node *children[ALPHABET_SIZE];
    bool isEnd;
    Node () {
        for (Node *child: children) {
            child = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
    public:
        Node *root;

        string longestWord(vector<string> words) {
            if (words.size()) {
                buildTrie(words);
            }
            return "";
        }

        string longestWordSearch() {
            string s, res;
            dfs(root, s, res);
            return res;
        }

        void dfs(Node* root, string & s, string & res) {
            if (root->isEnd) {
                if (s.size() > res.size()) {
                    res = s;
                }
            }

            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (root->children[i] && root->children[i]->isEnd) {
                    s.push_back(i + 'a');
                    dfs(root->children[i], s, res);
                    s.pop_back();
                }
            }
        }

        bool search(const string &word) {
            Node* pCrawl = root;
            for (char c:word) {
                int i = c - 'a';
                if (!pCrawl->children[i]) return false;
                pCrawl = pCrawl->children[i];
            }
            return true;
        }

    private:
        void buildTrie(const vector<string> &words) {
            root = new Node();
            for (string word:words) {
                insertKey(word);
            }
        }

        void insertKey(const string& word) {
            Node* pCrawl = root;
            for (char c:word) {
                int i = c - 'a';
                if (!pCrawl->children[i]) {
                    pCrawl->children[i] = new Node();
                }
                pCrawl = pCrawl->children[i];
            }
            if (pCrawl) pCrawl->isEnd = true;
        }
};

#endif /* ifndef SOLUTION_H__ */
