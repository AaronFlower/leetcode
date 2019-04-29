#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        size_t sLen = s.size();
        size_t pLen = p.size();

        if (pLen > sLen) {
            return res;
        }

        // Initialize the window
        unordered_map<char, int> map;
        for (size_t i = 0; i < pLen; ++i) {
            if (map.find(p[i]) != map.cend()) {
                map[p[i]] ++;
            } else {
                map[p[i]] = 1;
            }
        }

        size_t mSize = map.size();
        size_t begin = 0;

        for (size_t i = 0; i < sLen; ++i) {
            char ch = s[i];
            if (map.find(ch) != map.cend()) {
                map[ch]--;
                if (map[ch] == 0) {
                    mSize--;
                }
            }

            while (mSize == 0) {
                // try to find the right anagram and restore the window.
                ch = s[begin];
                if (map.find(ch) != map.cend()) {
                    map[ch]++;
                    if (map[ch] == 1) {
                        mSize++;
                    }
                }
                if (i + 1 - begin == pLen) {
                    res.push_back(begin);
                }
                ++begin;
            }
        }

        return res;
    }

};

#endif
