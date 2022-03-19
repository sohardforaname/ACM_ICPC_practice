#include "../base.h"

/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        deque<int> maxq, minq;
        size_t maxn = 0, lc = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (maxq.size() && nums[maxq.back()] < nums[i]) {
                maxq.pop_back();
            }
            while (minq.size() && nums[minq.back()] > nums[i]) {
                minq.pop_back();
            }
            maxq.push_back(i);
            minq.push_back(i);
            while (nums[maxq.front()] - nums[minq.front()] > limit) {
                if (nums[lc] == nums[maxq.front()])
                    maxq.pop_front();
                if (nums[lc] == nums[minq.front()])
                    minq.pop_front();
                ++lc;
            }
            maxn = max(maxn, i - lc + 1);
        }
        return maxn;
    }
};
// @lc code=end
