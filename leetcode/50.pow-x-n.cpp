#include "../base.h"
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double pow_(double a, unsigned int b)
    {
        double res = 1;
        while (b) {
            if (b & 1)
                res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        double num = pow_(x, abs(n));
        if (n < 0)
            return 1.0 / num;
        return num;
    }
};
// @lc code=end
