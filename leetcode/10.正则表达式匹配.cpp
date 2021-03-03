#include "../base.h"
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool dp[30][30];
    bool isMatch(string s, string p)
    {
        auto match = [&](int i, int j) -> bool {
            if (i == 0) // 匹配类似于"b"和"a*b"情况
                return false;
            if (p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };
        dp[0][0] = true;
        int n = s.size(), m = p.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2]; //不匹配a*
                    if (match(i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                } else if (match(i, j))
                    dp[i][j] |= dp[i - 1][j - 1]; //正常匹配
            }
        }
        return dp[n][m];
    }
};
// @lc code=end
