#include "../base.h"
/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        multiset<long> s1;
        multiset<long> s2;
        vector<double> v;
        for (int i = 0; i < nums.size(); ++i) {
            if (!s1.size() || nums[i] <= *(--s1.end()))
                s1.insert(nums[i]);
            else
                s2.insert(nums[i]);
            if (i < k - 1)
                continue;
            if (i >= k) {
                auto it = s1.find(nums[i - k]);
                if (it != s1.end()) {
                    s1.erase(it);
                } else {
                    s2.erase(s2.find(nums[i - k]));
                }
            }
            while (s1.size() > s2.size()) {
                s2.insert(*(--s1.end()));
                s1.erase(--s1.end());
            }
            while (s1.size() < s2.size()) {
                s1.insert(*s2.begin());
                s2.erase(s2.begin());
            }
            if ((s1.size() + s2.size()) % 2)
                v.emplace_back(*(--s1.end()));
            else
                v.emplace_back((*(--s1.end()) + *s2.begin()) / 2.0);
        }
        return v;
    }
};
// @lc code=end
