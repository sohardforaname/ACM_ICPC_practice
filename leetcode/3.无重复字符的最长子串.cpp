#include "../base.h"
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(const string& s)
    {
        int prev[128];
        memset(prev, -1, sizeof(prev));
        int maxn = 0, n = s.size(), l = 0;
        for (int i = 0; i < n; ++i) {
            if (prev[s[i]] >= l) {
                l = prev[s[i]] + 1;
            }
            prev[s[i]] = i;
            maxn = max(i - l + 1, maxn);
        }
        return maxn;
    }
};
// @lc code=end
