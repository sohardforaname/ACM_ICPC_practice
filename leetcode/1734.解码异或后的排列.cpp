#include "../base.h"
/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(const vector<int>& encoded)
    {
        int n = encoded.size();
        vector<int> v(n + 1);
        int xorsum = 0, xorall = 0;
        for (int i = 1; i <= n + 1; ++i)
            xorall ^= i;
        for (int i = 1; i < n; i += 2)
            xorsum ^= encoded[i];
        int a1 = xorsum ^ xorall;
        v[0] = a1;
        for (int i = 1; i < n + 1; ++i) {
            v[i] = v[i - 1] ^ encoded[i - 1];
        }
        return move(v);
    }
};
// @lc code=end
