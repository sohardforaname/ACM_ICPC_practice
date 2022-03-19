#include "../base.h"
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    string s;
    void dfs(int n, vector<string>& res, int l, int r)
    {
        if (l > n || r > n || l < r)
            return;
        if (l == n && r == n)
            res.emplace_back(s);
        s.push_back('(');
        dfs(n, res, l + 1, r);
        s.pop_back();
        s.push_back(')');
        dfs(n, res, l, r + 1);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        dfs(n, v, 0, 0);
        return move(v);
    }
};
// @lc code=end
