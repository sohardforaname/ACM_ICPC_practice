#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int dfn[N], low[N], clk;
vector<int> scc[N];
int sta[N], c[N], top, scc_cnt;
bool vis[N];
void dfs(int u)
{
    dfn[u] = low[u] = ++clk;
    sta[++top] = u;
    vis[u] = 1;
    for (auto i : G[u])
    {
        if (!dfn[i])
        {
            dfs(i);
            low[u] = min(low[u], low[i]);
        }
        else if (vis[i])
            low[u] = min(low[u], dfn[i]);
    }
    if (dfn[u] == low[u])
    {
        ++scc_cnt;
        int y;
        do
        {
            y = sta[top--];
            vis[y] = 0;
            c[y] = scc_cnt;
            scc[scc_cnt].push_back(y);
        } while (u != y);
    }
}
int n, m;
void tarjan()
{
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            dfs(i);
}
vector<int> G1[N], G2[N];
int dis1[N], dis2[N];
void build()
{
    for (int i = 1; i <= n; ++i)
        for (auto j : G[i])
            if (c[j] != c[i])
            {
                G1[c[i]].push_back(c[j]);
                G2[c[j]].push_back(c[i]);
            }
}
void spfa(int s, vector<int> *G, int *dis)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = scc[s].size();
    while (q.size())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (auto i : G[now])
            if (dis[i] < dis[now] + scc[i].size())
            {
                dis[i] = dis[now] + scc[i].size();
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    tarjan();
    build();
    spfa(c[1], G1, dis1);
    spfa(c[1], G2, dis2);
    int ans = 0;
    for (int i = 1; i <= scc_cnt; ++i)
        for (auto j : G1[i])
            if (dis1[j] > 0 && dis2[i] > 0)
                ans = max(ans, dis1[j] + dis2[i] - dis1[c[1]]);

    printf("%d\n", ans);
    return 0;
}