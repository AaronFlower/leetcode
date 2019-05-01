#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        unordered_map<char, int> map;
        char ch;
        for (size_t i = 0; i < t.size(); ++i) {
            ch = t[i];
            if (map.find(ch) != map.end()) {
                ++map[ch];
            } else {
                map[ch] = 1;
            }
        }

        int wBegin = -1;
        size_t  counter = 0, i = 0;
        string str;
        size_t minLen = s.size();
        while (i < s.size()) {
            ch = s[i];
            if (map.find(ch) != map.end()) {
                --map[ch];
                if (map[ch] == 0) {
                    ++counter;
                }
            }

            if (counter == map.size()) {
                do {
                    ++wBegin;
                    ch = s[wBegin];
                    if (map.find(ch) != map.end()) {
                        map[ch] += 1;
                        if (map[ch] == 1) {
                            --counter;
                            break;
                        }
                    }
                } while(1);

                if (i - wBegin + 1 <= minLen) {
                    minLen = i - wBegin + 1;
                    str = s.substr(wBegin, minLen);
                }
            }
            ++i;
        }
        return str;
    }
};

#endif
