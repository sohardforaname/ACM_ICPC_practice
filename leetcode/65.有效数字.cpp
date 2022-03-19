#include "../base.h"
/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s)
    {
        static regex reg(R"(^\s*[+-]?([0-9]+(\.[0-9]*)?|\.[0-9]+)([Ee][+-]?[0-9]+)?\s*$)", regex::optimize);
        return regex_match(s, reg);
    }
};
// @lc code=end
