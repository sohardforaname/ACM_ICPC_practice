#include "../base.h"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> v;
        if (nums.size() < 3)
            return move(v);
        vector<int> v1(3, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (tmp < 0) {
                    int nxt = l;
                    while (nxt < r && nums[nxt] == nums[l])
                        ++nxt;
                    l = nxt;
                } else if (tmp > 0) {
                    int nxt = r;
                    while (l < nxt && nums[nxt] == nums[r])
                        --nxt;
                    r = nxt;
                } else {
                    v1[0] = nums[i], v1[1] = nums[l], v1[2] = nums[r];
                    int nxt = l;
                    while (nxt < r && nums[nxt] == nums[l])
                        ++nxt;
                    l = nxt;
                    nxt = r;
                    while (l < nxt && nums[nxt] == nums[r])
                        --nxt;
                    r = nxt;
                    v.emplace_back(v1);
                }
            }
        }
        return move(v);
    }
};
// @lc code=end
