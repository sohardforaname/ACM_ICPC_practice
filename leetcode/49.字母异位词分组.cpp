#include "../base.h"
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        string tmp;
        for (auto& str : strs) {
            tmp = str;
            sort(str.begin(), str.end());
            mp[str].emplace_back(tmp);
        }
        vector<vector<string>> v;
        vector<string> v1;
        for (auto& it : mp) {
            v1.clear();
            for (auto& str : it.second)
                v1.emplace_back(str);
            v.emplace_back(v1);
        }
        return move(v);
    }
};
// @lc code=end
