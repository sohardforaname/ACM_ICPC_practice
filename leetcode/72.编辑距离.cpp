#include "../base.h"
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
    vector<vector<int>> dp;
    int minDistance(const string& word1, const string& word2)
    {
        if (!word1.size() || !word2.size()) {
            return this->max(word1.size(), word2.size());
        }
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, 0x3f3f3f3f));
        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = this->min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = this->min(dp[i][j], dp[i][j - 1] + 1);
                    dp[i][j] = this->min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
