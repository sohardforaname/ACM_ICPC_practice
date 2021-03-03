#include "../base.h"
/*
 * @lc app=leetcode.cn id=736 lang=cpp
 *
 * [736] Lisp 语法解析
 */

// @lc code=start
class Solution {
public:
    int cur;
    string& expr;
    char take()
    {
        if (expr.size() > cur + 1)
            return expr[++cur];
        return ')';
    }
    char seek()
    {
        if (expr.size() > cur + 1)
            return expr[cur + 1];
        return ')';
    }
    int evaluate(const string& expression)
    {
        expr = expression;
    }
};
// @lc code=end
