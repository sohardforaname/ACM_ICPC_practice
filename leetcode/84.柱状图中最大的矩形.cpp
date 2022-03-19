#include "../base.h"
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        heights.push_back(0);
        stack<int> s;
        int sum = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (s.size() && heights[i] < heights[s.top()]) {
                int pos = s.top();
                s.pop();
                int tmp = (s.size() ? (i - s.top() - 1) : i) * heights[pos];
                sum = max(sum, tmp);
            }
            s.push(i);
        }

        return sum;
    }
};
// @lc code=end
