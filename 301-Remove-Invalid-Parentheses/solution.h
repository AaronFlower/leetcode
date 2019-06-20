#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <string>
#include <unordered_set>
#include <stack>

using std::vector;
using std::string;
using std::unordered_set;
using std::stack;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int min;

        stack<char> st;
        for (char c: s) {
            switch (c) {
                case '(':
                    st.push(c);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') {
                        st.push(c);
                    } else {
                        st.pop();
                    }
                    break;
                default:
                    break;
                    // do nothing;
            }
        }

        min = st.size();

        if (min > 0) {
            removeHelper(s, 0, min, res);
        } else {
            res.insert(s);
        }

        vector<string> r(res.begin(), res.end());

        return r;
    }

    bool isValidUsingCounter(string s) {
        int left = 0;
        for (char c:s) {
            if (c == '(') ++left;
            if (c == ')') {
                if (left == 0) {
                    return false;
                } else {
                    --left;
                }
            }
        }
        return left == 0;
    }

    bool isValid(string s) {
        stack<char> st;
        for (char c:s) {
            switch (c) {
                case '(':
                    st.push(c);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') {
                        return false;
                    } else {
                        st.pop();
                    }
                    break;
            }
        }
        return st.empty();
    }

    void removeHelper(string s, int deleted, int min, unordered_set<string> &res) {
        if (deleted == min && isValidUsingCounter(s)) {
            if (res.find(s) == res.end())
                res.insert(s);
            return;
        }

        for (size_t i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == ')') {
                // delete
                s.erase(s.begin() + i);
                removeHelper(s, deleted + 1, min, res);
                s.insert(s.begin() + i, ch);
            }
        }
    }
};

#endif
