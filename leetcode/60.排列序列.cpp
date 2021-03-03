#include "../base.h"
/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k)
    {
        --k;
        string ans = "";
        const int p[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        vector<bool> vis(11, false);
        for (int i = n - 1; ~i; --i) {
            int quo = k / p[i] + 1;
            k %= p[i];
            int j;
            for (j = 1; j <= n; ++j)
                if (!vis[j] && !(--quo)) {
                    break;
                }
            vis[j] = true;
            ans.push_back(char(j + '0'));
        }
        return move(ans);
    }
};
// @lc code=end
