/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
typedef pair<int, int> pii;

template <>
struct equal_to<pii> {
    bool operator()(const pii& a, const pii& b) const
    {
        return a.first == b.first && a.second == b.second;
    }
};

template <>
struct hash<pii> {
    size_t operator()(const pii& a) const
    {
        return (hash<int> {}(a.first) << 32) + hash<int> {}(a.second);
    }
};

class Solution {
public:
    unordered_map<int, int> diff1;
    unordered_map<int, int> diff2;
    unordered_set<pair<int, int>> light;
    unordered_map<int, int> px, py;
    int n_;
    bool check(int x, int y)
    {
        return x >= 0 && x < n_ && y >= 0 && y < n_;
    }
    void change(int x, int y)
    {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int dx = x + i, dy = y + j;
                if (check(dx, dy) && light.count({ dx, dy })) {
                    light.erase({ dx, dy });
                    diff1[dx - dy]--;
                    diff2[dx + dy]--;
                    px[dx]--;
                    py[dy]--;
                }
            }
        }
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries)
    {
        n_ = n;
        for (auto& v : lamps) {
            int x = v[0], y = v[1];
            if (light.count({ x, y })) {
                continue;
            }
            diff1[x - y]++;
            diff2[x + y]++;
            px[x]++;
            py[y]++;
            light.emplace(x, y);
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& v : queries) {
            int x = v[0], y = v[1];
            ans.emplace_back(diff1[x - y] > 0 || diff2[x + y] > 0 || px[x] > 0 || py[y] > 0);
            change(x, y);
        }
        return ans;
    }
};
// @lc code=end
