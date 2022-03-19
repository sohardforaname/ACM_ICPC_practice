#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int dfn[N], low[N], clk;
bool ins[N];
int sta[N], c[N], scc_cnt, top;
vector<int> scc[N << 1];
void dfs(int u)
{
    dfn[u] = low[u] = ++clk;
    ins[u] = 1;
    sta[++top] = u;
    for (auto i : G[u])
    {
        if (!dfn[i])
        {
            dfs(i);
            low[u] = min(low[u], low[i]);
        }
        else if (ins[i])
            low[u] = min(low[u], dfn[i]);
    }
    if (dfn[u] == low[u])
    {
        int y;
        ++scc_cnt;
        do
        {
            y = sta[top--];
            c[y] = scc_cnt;
            scc[scc_cnt].push_back(y);
            ins[y] = 0;
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
int dis[N << 1];
vector<int> G1[N << 1];
void build()
{
    for (int i = 1; i <= scc_cnt; ++i)
        scc[i + scc_cnt] = scc[i];
    for (int i = 1; i <= n; ++i)
        for (auto j : G[i])
            if (c[i] != c[j])
            {
                G1[c[i]].push_back(c[j]);
                G1[c[i] + scc_cnt].push_back(c[j] + scc_cnt);
                G1[c[j]].push_back(c[i] + scc_cnt);
            }
}
bool vis[N << 1];
void spfa(int s)
{
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (auto i : G1[now])
        {
            if (dis[i] < dis[now] + scc[i].size())
            {
                dis[i] = dis[now] + scc[i].size();
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
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
    spfa(c[1]);
    printf("%d\n", dis[c[1] + scc_cnt]);
    return 0;
}