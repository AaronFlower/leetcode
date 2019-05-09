#ifndef SOLUTION_H__
#define SOLUTION_H__

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;


class Solution {
public:
    struct Node {
        Node *children[26];
        bool isEnd;

        Node ():isEnd(false) {
            for (auto &c:children) {
                c = nullptr;
            }
        }
    };

    class Trie {
    public:
        Trie() {
            root = new Node();
        }

        ~Trie() {
            destroy(root);
        }

        void insert(string s) {
            Node *p = root;

            for(auto c:s) {
                int i = c - 'a';
                if (!p->children[i]) {
                    p->children[i] = new Node();
                }
                p = p->children[i];
            }
            p->isEnd = true;
        }

        string searchPrefix(string &w) {
            string s;

            Node *p = root;
            for (auto c:w) {
                int i = c - 'a';
                if (!p->children[i]) {
                    return "";
                }
                p = p->children[i];
                s += c;
                if (p->isEnd) {
                    return s;
                }
            }
            return "";
        }


    private:
        Node *root;

        void destroy(Node *node) {
            if (node) {
                for (auto n:node->children) {
                    destroy(n);
                }
                delete node;
            }
        }
    };
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie t;

        for (auto w:dict) {
            t.insert(w);
        }

        vector<string> words;
        string w, prefix;
        istringstream is(sentence);
        while (is >> w) {
            prefix = t.searchPrefix(w);
            if (prefix.size() > 0) {
                words.push_back(prefix);
            } else {
                words.push_back(w);
            }
        }

        ostringstream os;
        int i = 0;
        for (auto w:words) {
            if (i++ != 0) {
                os << " ";
            }
            os << w;
        }
        return os.str();
    }
};

#endif /* ifndef SOLUTION_H__ */
