#include "../base.h"
/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p)
    {
        auto match = [&](int i, int j) -> bool {
            if (p[j - 1] == '?')
                return true;
            return s[i - 1] == p[j - 1];
        };
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] != '*') {
                break;
            }
            dp[0][i + 1] = 1;
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] != '*') {
                    if (match(i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                } else {
                    dp[i][j] |= dp[i - 1][j] | dp[i][j - 1];
                }
            }
        }
        //return 0;
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
