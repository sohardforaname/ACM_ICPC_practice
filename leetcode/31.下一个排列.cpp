#include "../base.h"
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() < 2)
            return;
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1])
                break;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        for (; j > i; --j) {
            if (nums[i] < nums[j])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
