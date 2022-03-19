#include "../base.h"
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int step = 0;
        for (int i = 0; i < nums.size() - 1;) {
            int maxpos = i, maxn = 0;
            if (i + nums[i] >= nums.size() - 1) {
                ++step;
                break;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + nums[i])
                    break;
                if (maxn < j + nums[j])
                    maxpos = j, maxn = j + nums[j];
            }
            ++step;
            //cout << i << " " << maxpos << endl;
            i = maxpos;
        }
        return step;
    }
};
// @lc code=end
