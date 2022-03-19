#include "../base.h"
/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题?
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> buf;
        int len = 0;
        for (int i = 0; i < envelopes.size(); ++i) {
            int num = envelopes[i][1];
            auto it = lower_bound(buf.begin(), buf.end(), num);
            if (it == buf.end()) {
                buf.push_back(num);
                ++len;
            } else {
                *it = num;
            }
        }
        return len;
    }
};
// @lc code=end
