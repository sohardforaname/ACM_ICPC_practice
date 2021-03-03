#include "../base.h"
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height)
    {
        stack<int> s;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (s.size() && height[s.top()] < height[i]) {
                int top = s.top();
                s.pop();
                if (s.empty())
                    break;
                int bound = min(height[i], height[s.top()]) - height[top];
                sum += bound * (i - s.top() - 1);
            }
            s.push(i);
        }
        return sum;
    }
};
// @lc code=end
