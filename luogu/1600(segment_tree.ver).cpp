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
int sum[N * 65], ls[N * 65], rs[N * 65];
int cnt, rt[N];
void update(int &rt, int l, int r, int pos, int val)
{
    if (!rt)
        rt = ++cnt;
    sum[rt] += val;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (pos <= m)
        update(ls[rt], l, m, pos, val);
    else if (pos > m)
        update(rs[rt], m + 1, r, pos, val);
}
void merge(int &lt, int rt, int l, int r)
{
    if (!lt || !rt)
    {
        lt += rt;
        return;
    }
    sum[lt] += sum[rt];
    if (l == r)
        return;
    int m = (l + r) >> 1;
    merge(ls[lt], ls[rt], l, m);
    merge(rs[lt], rs[rt], m + 1, r);
}
int query(int rt, int l, int r, int pos)
{
    if (!rt)
        return 0;
    if (l == r)
        return sum[rt];
    int m = (l + r) >> 1;
    if (pos <= m)
        return query(ls[rt], l, m, pos);
    else if (pos > m)
        return query(rs[rt], m + 1, r, pos);
}
int ans[N];
int w[N];
void dfs2(int u, int fa)
{
    for (auto i : G[u])
        if (i != fa)
        {
            dfs2(i, u);
            merge(rt[u], rt[i], 1, n << 1);
        }
    if (w[u] && w[u] + dep[u] <= n)
        ans[u] += query(rt[u], 1, n << 1, n + dep[u] + w[u]);
    ans[u] += query(rt[u], 1, n << 1, n + dep[u] - w[u]);
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
        int s, t;
        scanf("%d%d", &s, &t);
        int lca = get_lca(s, t);
        update(rt[s], 1, n << 1, n + dep[s], 1);
        update(rt[t], 1, n << 1, n + (dep[lca] << 1) - dep[s], 1);
        update(rt[lca], 1, n << 1, n + dep[s], -1);
        update(rt[f[lca][0]], 1, n << 1, n + (dep[lca] << 1) - dep[s], -1);
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}