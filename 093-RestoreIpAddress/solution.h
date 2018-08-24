#ifndef LEET_CODE_H__
#define LEET_CODE_H__ 

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;
using std::stringstream;
using std::cout;

class Solution {
public:
    string join(vector<string> subIps) {
        stringstream ss;
        int i = 0;
        for (auto ip:subIps) {
            if (i++ != 0)
                ss << ".";
            ss << ip;
        }
        return ss.str();
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        getIp(s, 0, {}, res);
        return res;
    }
private:
    bool isSafe(string ip) {
        if (ip.size() == 1) {
            return true;
        } else if (ip[0] != '0') {
            return (ip.size() == 2 || ip <= "255");
        }
        return false;
    };
    void getIp(string& s, size_t start, vector<string> ip, vector<string>& res) {
        if (ip.size() >= 4) {
            if (start == s.size()) 
                res.push_back(join(ip));
            return;
        } else {
            for (int i = 1; i <= 3; ++i) {
                try {
                    string subIp = s.substr(start, i);
                    if (isSafe(subIp)) {
                        ip.push_back(subIp);
                        getIp(s, start + i, ip, res);
                        ip.pop_back(); 
                    }  
                } catch (const std::out_of_range &e) {
                }
            }
        }
    }
};

#endif /* ifndef LEET_CODE_H__ */
