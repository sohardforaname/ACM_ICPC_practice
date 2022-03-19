#include "../base.h"
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        for (int i = 2; i <= s.size(); ++i) {
            if (s[i - 1] == ')' && s[i - 2] == '(')
                dp[i] = dp[i - 2] + 2;
            else if (s[i - 1] == ')' && s[i - 2] == ')')
                if (i - dp[i - 1] - 2 >= 0 && s[i - dp[i - 1] - 2] == '(')
                    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
