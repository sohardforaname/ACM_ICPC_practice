#include "../base.h"
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int maxn = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (maxn + 1 == nums[i])
                maxn = nums[i];
        return maxn + 1;
    }
};
// @lc code=end
