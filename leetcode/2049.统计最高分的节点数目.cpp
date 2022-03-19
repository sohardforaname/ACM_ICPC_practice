#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> g;
    vector<long long> pnts, sz;
    int tot;
    void dfs1(int u)
    {
        sz[u] = 1;
        for (auto& v : g[u]) {
            dfs1(v);
            sz[u] += sz[v];
        }
    }
    void dfs2(int u)
    {
        long long pnt = max(tot - sz[u], 1ll);
        for (auto& v : g[u]) {
            dfs2(v);
            pnt *= sz[v];
        }
        pnts.push_back(pnt);
    }
    int countHighestScoreNodes(const vector<int>& parents)
    {
        g.resize(parents.size());
        sz.resize(parents.size());
        tot = parents.size();
        int root = 0;
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i] != -1) {
                g[parents[i]].push_back(i);
            } else {
                root = i;
            }
        }
        dfs1(root);
        dfs2(root);
        sort(pnts.begin(), pnts.end());
        int ans = 0;
        for (int i = pnts.size() - 1; i >= 0; --i) {
            if (pnts[i] == pnts.back()) {
                ++ans;
            }
        }
        return ans;
    }
};