#include "../base.h"
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> v;
    vector<int> v1;
    vector<bool> check;
    void dfs(const vector<int>& vn)
    {
        if (v1.size() == vn.size()) {
            v.emplace_back(v1);
            return;
        }
        for (int i = 0; i < vn.size(); ++i) {
            if (check[i])
                continue;
            if (i > 0 && vn[i] == vn[i - 1] && check[i - 1] == 0)
                continue;
            check[i] = 1;
            v1.emplace_back(vn[i]);
            dfs(vn);
            v1.pop_back();
            check[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        check.resize(10);
        v1.reserve(10);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return move(v);
    }
};
// @lc code=end
