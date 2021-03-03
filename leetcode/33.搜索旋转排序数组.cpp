#include "../base.h"
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int ed = nums.back();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] > ed)
                l = m + 1;
            else
                r = m;
        }
        if (l == 0 || target <= ed) {
            auto it = lower_bound(nums.begin() + l, nums.end(), target);
            if (it == nums.end() || *it != target)
                return -1;
            return it - nums.begin();
        }
        auto it = lower_bound(nums.begin(), nums.begin() + l, target);
        if (it == nums.begin() + l || *it != target)
            return -1;
        return it - nums.begin();
    }
};
// @lc code=end
