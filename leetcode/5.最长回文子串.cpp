#include "../base.h"
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    char ma[2005];
    int mp[2005];
    string longestPalindrome(const string& s)
    {
        memset(ma, 0, sizeof(ma));
        memset(mp, 0, sizeof(mp));
        int len = s.size();
        int l = 0;
        int st = 0, maxn = 0;
        ma[l++] = '$';
        ma[l++] = '#';
        for (int i = 0; i < len; ++i) {
            ma[l++] = s[i];
            ma[l++] = '#';
        }
        ma[l] = 0;
        int mx = 0, id = 0;
        for (int i = 0; i < l; ++i) {
            mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
            while (i + mp[i] < l && i - mp[i] >= 0 && ma[i + mp[i]] == ma[i - mp[i]])
                ++mp[i];
            if (i + mp[i] > mx) {
                mx = i + mp[i];
                id = i;
                if (maxn < mp[i]) {
                    st = (i - mp[i]) / 2;
                    maxn = mp[i];
                }
            }
        }
        return std::move(s.substr(st, maxn - 1));
    }
};
// @lc code=end
