#include "../base.h"
/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(const string& preorder)
    {
        int slot = 1;
        for (int i = 0; i < preorder.size();) {
            if (preorder[i] == '#') {
                ++i;
                if (!slot) {
                    return false;
                }
                --slot;
            } else if (isdigit(preorder[i])) {
                int tmp = 0;
                while (isdigit(preorder[i])) {
                    tmp = tmp * 10 + preorder[0] - '0';
                    ++i;
                }
                if (!slot) {
                    return false;
                }
                slot += 1;
            } else {
                ++i;
            }
        }
        return !slot;
    }
};
// @lc code=end
