#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N], rG[N];
pair<int, int> e[N];
map<pair<int, int>, int> mp;
bool vis[N];
void dfs1(int u)
{
    vis[u] = 1;
    for (auto &i : G[u])
        if (!vis[i])
        {
            ++mp[make_pair(u, i)];
            dfs1(i);
        }
}
void dfs2(int u)
{
    vis[u] = 1;
    for (auto &i : rG[u])
        if (!vis[i])
        {
            ++mp[make_pair(i, u)];
            dfs2(i);
        }
}
void solve()
{
    mp.clear();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        G[i].clear();
        rG[i].clear();
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        rG[v].push_back(u);
        e[i] = {u, v};
    }
    memset(vis, 0, sizeof(vis[0]) * (n + 1));
    dfs1(1);
    memset(vis, 0, sizeof(vis[0]) * (n + 1));
    dfs2(1);
    int cnt = 0;
    for (int i = 1; i <= m && cnt != m - 2 * n; ++i)
        if (mp.find(e[i]) == mp.end())
            ++cnt, printf("%d %d\n", e[i].first, e[i].second);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
/*
1
4 9
1 2
1 3
2 3
2 4
3 2
3 4
4 1
4 2
4 3
*/