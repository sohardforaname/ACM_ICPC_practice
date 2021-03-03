#include "../base.h"
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之�?
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 0, minn = 0x3f3f3f3f;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target)
                    ++l;
                else if (sum > target)
                    --r;
                else
                    return sum;
                if (abs(sum - target) < minn) {
                    minn = abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;
    }
};
// @lc code=end
