#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__ 
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::to_string;

class Solution {
public:
    using strvec = vector<string>;

    strvec addOperators(string num, long target) {
        strvec res;
        if (!num.empty()) {
            size_t len = num.size();
            for (size_t i = 1; i <= len; ++i) {
                string s = num.substr(0, i);
                long now = stol(s);
                if (std::to_string(now).size() != s.size()) continue;
                dfs(res, num, target, i, s, now, now, '#');
            }
        } 
        return res;
    }


    void dfs(strvec &res, const string num, const long target, 
            size_t pos, string cur, long cv, long pov, char op) {

        if (num.size() == pos && target == cv) {
            res.push_back(cur);
        } else {
            for (size_t j = pos + 1; j <= num.size(); ++j) {
                string s = num.substr(pos, j - pos);
                long now = stol(s);
                if (std::to_string(now).size() != s.size()) continue;
                dfs(res, num, target, j, cur + '+' + s, cv + now, now, '+');
                dfs(res, num, target, j, cur + '-' + s, cv - now, now, '-');

                long newCv = cv * now;
                if (op == '+') {
                    newCv = cv - pov + pov * now;
                } else if (op == '-') {
                    newCv = cv + pov - pov * now;
                }
                dfs(res, num, target, j, cur + '*' + s, newCv, pov * now, op);
            }
        }
    }
};

#endif
