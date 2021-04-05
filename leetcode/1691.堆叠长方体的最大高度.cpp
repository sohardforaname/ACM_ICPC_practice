#include "../base.h"
/*
 * @lc app=leetcode.cn id=1691 lang=cpp
 *
 * [1691] 堆叠长方体的最大高度
 */

// @lc code=start
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids)
    {
        for (auto& cub : cuboids) {
            sort(cub.begin(), cub.end());
        }
        sort(cuboids.begin(), cuboids.end(), [&](const auto& a, const auto& b) -> bool {
            return forward_as_tuple(a[2], a[1], a[0]) < forward_as_tuple(b[2], b[1], b[0]);
        });
        vector<int> dp(cuboids.size(), 0);
        for (int i = 0; i < cuboids.size(); ++i) {
            int maxn = 0;
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][0] <= cuboids[i][0]) {
                    maxn = max(maxn, dp[j]);
                }
            }
            dp[i] = maxn + cuboids[i][2];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
