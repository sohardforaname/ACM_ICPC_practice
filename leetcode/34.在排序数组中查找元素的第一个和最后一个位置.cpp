#include "../base.h"
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int LowerBound(vector<int>& v, int val)
    {
        int l = 0, r = v.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (v[m] >= val)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    int UpperBound(vector<int>& v, int val)
    {
        int l = 0, r = v.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (v[m] > val)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int l = LowerBound(nums, target);
        int r = UpperBound(nums, target);
        if (l == nums.size() || nums[l] != target)
            return move(vector<int>({ -1, -1 }));
        return move(vector<int>({ l, r - 1 }));
    }
};
// @lc code=end
