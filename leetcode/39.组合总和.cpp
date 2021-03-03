#include "../base.h"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<int> v1;
    void dfs(vector<vector<int>>& v, const vector<int>& vn, int pos, int sum, int target)
    {
        if (sum > target)
            return;
        if (sum == target) {
            v.emplace_back(v1);
            return;
        }
        for (int i = pos; i < vn.size(); ++i) {
            v1.push_back(vn[i]);
            dfs(v, vn, i, sum + vn[i], target);
            v1.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> v;
        dfs(v, candidates, 0, 0, target);
        return move(v);
    }
};
// @lc code=end
