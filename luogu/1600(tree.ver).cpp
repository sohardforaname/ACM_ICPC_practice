#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<int> G[N];
int dep[N], f[N][20];
int n, m;
void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i < 20; ++i)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (auto i : G[u])
        if (i != fa)
            dfs(i, u);
}
int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; ~i; --i)
        if ((1 << i) & (dep[u] - dep[v]))
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 19; ~i; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
vector<int> t_[N], lca_[N];
int w[N];
int buc1[N << 1], buc2[N << 1];
int cnts[N], dist[N];
int s[N], t[N];
int ans[N];
void dfs2(int u, int fa)
{
    int tmp1 = buc1[w[u] + dep[u]], tmp2 = buc2[w[u] - dep[u] + N];
    for (auto i : G[u])
        if (i != fa)
            dfs2(i, u);
    buc1[dep[u]] += cnts[u];
    for (auto i : t_[u])
        ++buc2[dist[i] - dep[t[i]] + N];
    ans[u] += buc1[w[u] + dep[u]] - tmp1 + buc2[w[u] - dep[u] + N] - tmp2;
    for (auto i : lca_[u])
    {
        --buc1[dep[s[i]]];
        --buc2[dist[i] - dep[t[i]] + N];
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &s[i], &t[i]);
        ++cnts[s[i]];
        int lca = get_lca(s[i], t[i]);
        t_[t[i]].push_back(i);
        lca_[lca].push_back(i);
        dist[i] = dep[s[i]] + dep[t[i]] - (dep[lca] << 1);
        if (w[lca] + dep[lca] == dep[s[i]])
            --ans[lca];
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}