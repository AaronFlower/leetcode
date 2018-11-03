#ifndef SOLUTION_H__
#define SOLUTION_H__

#define ALPHABET_SIZE 26

#include <vector>
#include <string>

using std::vector;
using std::string;

struct TrieNode {
    TrieNode *children[26];
    bool isEnd;
    TrieNode() {
        for (TrieNode* &child:children) {
            child = nullptr;
        }
        isEnd = false;
    }
};


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    ~MagicDictionary() {
        destroy(root);
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) {
            insert(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode *pCrawl = root;
        int i;
        for (std::size_t j = 0; j < word.size(); ++j) {
            i = word[j] - 'a';
            if (pCrawl->children[i]) {
                pCrawl = pCrawl->children[i];
            } else {
                string subWord = word.substr(j + 1);
                for (int k = 0; k < 26; ++k) {
                    if (k != i && pCrawl->children[k] && searchHelper(pCrawl->children[k], subWord)) {
                        return true;
                    }
                }
                return false;
            } 
        }
        return false;
    }
private:
    TrieNode *root;
    
    void insert(const string &word) {
        TrieNode *pCrawl = root;
        int i;
        for (char c : word) {
            i = c - 'a';
            if (!pCrawl->children[i]) {
                pCrawl->children[i] = new TrieNode();
            }
            pCrawl = pCrawl->children[i];
        }
        pCrawl->isEnd = true;
    }
    
    bool searchHelper (TrieNode *root, const string &word) {
        int i;
        for (char c:word) {
            i = c - 'a';
            if (root->children[i]) {
                root = root->children[i];
            } else {
                return false;
            }
        }
        return root && root->isEnd;
    }
    
    void destroy(TrieNode *root) {
        if (root) {
            for (TrieNode *child:root->children) {
                destroy(child);
            }
            delete root;
        }
    }
};

#endif /* ifndef SOLUTION_H__ */
