/*
 * @lc app=leetcode.cn id=2047 lang=cpp
 *
 * [2047] 句子中的有效单词数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string str) {
        regex re("^([!,.]|[a-z]+(-[a-z]+)?[!,.]?)$");
        return regex_match(str.data(), re);
    }

    int countValidWords(string sentence) {
        auto ret = 0, len = 0;
        for (size_t i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                ret += isMatch(sentence.substr(i - len, len));
                len = 0;
            } else {
                ++len;
            }
        }
        ret += isMatch(sentence.substr(sentence.size() - len, len));
        return ret;
    }
};
// @lc code=end

