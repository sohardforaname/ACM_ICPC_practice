#include "../base.h"
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(const vector<int>& height)
    {
        int l = 0, r = height.size() - 1;
        int maxn = (r - l) * min(height[l], height[r]);
        while (l < r) {
            if (height[l] < height[r])
                ++l;
            else
                --r;
            maxn = max(maxn, (r - l) * min(height[l], height[r]));
        }
        return maxn;
    }
};
// @lc code=end
