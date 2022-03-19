#include "../base.h"
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(const string& s, int numRows)
    {
        if (numRows == 1)
            return move(s);
        string s1(s.size(), 0);
        int jp1 = 2 * numRows - 2, jp2 = 0;
        int cnt = 0;
        for (int i = 0; i < numRows; ++i) {
            int pos = i;
            bool f = 0;
            if (pos < s.size())
                s1[cnt++] = s[pos];
            while (pos < s.size()) {
                if (!f) {
                    pos += jp1;
                    if (pos < s.size() && jp1)
                        s1[cnt++] = s[pos];
                } else {
                    pos += jp2;
                    if (pos < s.size() && jp2)
                        s1[cnt++] = s[pos];
                }
                f = !f;
            }
            jp1 -= 2;
            jp2 += 2;
        }
        return move(s1);
    }
};
// @lc code=end
