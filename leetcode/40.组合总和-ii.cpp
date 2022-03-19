#include "../base.h"
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            if (i > pos && vn[i] == vn[i - 1])
                continue;
            v1.emplace_back(vn[i]);
            dfs(v, vn, i + 1, sum + vn[i], target);
            v1.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> v;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            v1.clear();
            if (i && candidates[i] == candidates[i - 1])
                continue;
            v1.emplace_back(candidates[i]);
            dfs(v, candidates, i + 1, candidates[i], target);
        }
        return move(v);
    }
};
// @lc code=end
