#include "../base.h"
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> isPar;
    void dfs(int pos, vector<string>& v, vector<vector<string>>& v1, const string& s)
    {
        if (pos == s.size()) {
            v1.push_back(v);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (isPar[pos][i]) {
                v.push_back(s.substr(pos, i - pos + 1));
                dfs(i + 1, v, v1, s);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        isPar.assign(s.size(), vector<bool>(s.size(), true));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < s.size(); ++j) {
                isPar[i][j] = isPar[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        vector<string> v;
        vector<vector<string>> v1;
        dfs(0, v, v1, s);
        return move(v1);
    }
};
// @lc code=end
