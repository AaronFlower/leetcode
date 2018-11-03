#ifndef SOLUTION_H__
#define SOLUTION_H__

#define ALPHABET_SIZE 26

#include <vector>
#include <string>

using std::vector;
using std::string;

struct TrieNode {
    struct TrieNode* children[26];
    bool isEnd;
    TrieNode () {
        for (TrieNode* & child:children) {
            child = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    Trie (vector<string>& words) {
        if (words.empty()) {
            root = nullptr;
        } else {
            root = new TrieNode();
            for (string word:words) {
                insert(word);
            }
        }
    }
    
    ~Trie() {
        destroy(root);
    }
    
    void insert(const string& word) {
        TrieNode* pCrawl = root;
        for (char c:word) {
            int i = c - 'a';
            if (!pCrawl->children[i]) {
                pCrawl->children[i] = new TrieNode();
            }
            pCrawl = pCrawl->children[i];
        }
        pCrawl->isEnd = true;
    }
    
    string searchLongestWord () {
        string s, res;
        dfs(root, s, res);
        return res;
    }
    
    void dfs(TrieNode* root, string& s, string& res) {
        if (!root) return;
        if (root->isEnd) {
            if (s.size() > res.size()) {
                res = s;
            }
        }
        
        // backtracking.
        for (int i = 0; i < 26; ++i) {
            if (root->children[i] && root->children[i]->isEnd) {
                s.push_back('a' + i);
                dfs(root->children[i], s, res);
                s.pop_back();
            }
        }
    }
    
private:
    TrieNode *root;
    
    void destroy(TrieNode* root) {
        if (root) {
            for (TrieNode* child:root->children) {
                destroy(child);
            }
            delete root;
        }
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t(words);
        return t.searchLongestWord();
    }
};

#endif /* ifndef SOLUTION_H__ */
