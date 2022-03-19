/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<pair<bool, bool>> v;

    string res = "";
    string longestNiceSubstring(const string& s)
    {
        v.resize(26);
        auto check = [&](const string& str) -> bool {
            for (auto& p : v) {
                p.first = p.second = false;
            }
            for (auto c : str) {
                if (isupper(c)) {
                    v[c - 'A'].first = true;
                } else {
                    v[c - 'a'].second = true;
                }
            }
            for (auto& p : v) {
                if (p.second != p.first) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                string str = s.substr(i, j - i + 1);
                if (check(str) && str.size() > res.size()) {
                    res = str;
                }
            }
        }
        return res;
    }
};
// @lc code=end
