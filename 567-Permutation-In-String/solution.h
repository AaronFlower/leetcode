#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty()) return true;

        unordered_map<char, int> map;
        char ch;
        for (size_t i = 0; i < s1.size(); ++i) {
            ch = s1[i];
            if (map.find(ch) != map.end()) {
                map[ch] += 1;
            } else {
                map[ch] = 1;
            }
        }

        int begin = -1;
        size_t counter = 0;

        for (size_t i = 0; i < s2.size(); ++i) {
            ch = s2[i];
            if (map.find(ch) != map.end()) {
                --map[ch];
                if (map[ch] == 0) {
                    ++counter;
                }
            }

            if (counter == map.size()) {
                do {
                    ++begin;
                    ch = s2[begin];
                    if (map.find(ch) != map.end()) {
                        map[ch]++;
                        if (map[ch] == 1) {
                            --counter;
                            break;
                        }
                    }
                } while (1);

                if (i - begin + 1 == s1.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif
