#include "../base.h"
/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串II
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    vector<vector<bool>> isPar;
    int minCut(string s)
    {
        dp.resize(s.size());
        isPar.resize(s.size(), vector<bool>(s.size(), true));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < s.size(); ++j) {
                isPar[i][j] = isPar[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            dp[i] = i;
        }
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (isPar[i][j]) {
                    if (i > 0)
                        dp[j] = min(dp[j], dp[i - 1] + 1);
                    else
                        dp[j] = 0;
                }
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end
