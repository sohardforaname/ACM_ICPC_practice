#include "../base.h"
/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int len = nums.size(), cnt = 0;
        vector<int> v(len, -1);
        stack<int> s;
        for (int i = 0; i < (len << 1); ++i) {
            while (s.size() && nums[i % len] > nums[s.top() % len]) {
                int pos = s.top();
                v[s.top() % len] = nums[i % len];
                s.pop();
                if (pos < len)
                    ++cnt;
                if (cnt == len)
                    return move(v);
            }
            s.push(i);
        }
        return move(v);
    }
};
// @lc code=end
