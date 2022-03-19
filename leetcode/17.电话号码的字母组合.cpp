#include "../base.h"
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合?
 */

// @lc code=start
class Solution {
public:
    string s[9] = {
        "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    string str;
    vector<string> v;
    void dfs(int div, int n, const string& digits)
    {
        if (div == n) {
            v.emplace_back(str);
            return;
        }
        if (digits[div] - '1' == 0)
            dfs(div + 1, n, digits);
        for (auto& ch : s[digits[div] - '1']) {
            str.push_back(ch);
            dfs(div + 1, n, digits);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(const string& digits)
    {
        if (!digits.size())
            return move(v);
        dfs(0, digits.size(), digits);
        return move(v);
    }
};
// @lc code=end
