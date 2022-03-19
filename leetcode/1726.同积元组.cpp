#include "../base.h"
/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> mp;
    int tupleSameProduct(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++mp[nums[i] * nums[j]];
            }
        }
        int ans = 0;
        for (auto& it : mp) {
            ans += 4 * (it.second) * (it.second - 1);
        }
        return ans;
    }
};
// @lc code=end
