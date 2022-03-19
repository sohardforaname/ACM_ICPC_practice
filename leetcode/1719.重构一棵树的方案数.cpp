/*
 * @lc app=leetcode.cn id=1719 lang=cpp
 *
 * [1719] 重构一棵树的方案数
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    set<int> s;
    map<int, int> mp;
    // find k nums, whose sum is sum
    vector<int> find(int sum)
    {
    }
    int checkWays(vector<vector<int>>& pairs)
    {
        for (auto& p : pairs) {
            for (auto& x : p) {
                ++mp[x];
            }
        }
        int sz = mp.size();
        for (auto& [x, y] : mp) {
            s.emplace(y + 1);
        }
        s.erase(s.begin());
        while (s.size()) {
            // 找到k个节点使得它们的出现次数和刚好是n - k - 1
            // 问题转化成找到k个数使其和是n - k - 1
        }
    }
};
// @lc code=end
