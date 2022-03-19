#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int f[N][18], dep[N];
int n, m;
vector<int> G[N];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (auto i : G[u])
        if (i != fa)
            dfs(i, u);
}
void init_lca()
{
    for (int i = 1; i < 18; ++i)
        for (int j = 1; j <= n; ++j)
            f[j][i] = f[f[j][i - 1]][i - 1];
}
int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 17; ~i; --i)
        if ((1 << i) & (dep[u] - dep[v]))
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 17; ~i; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
struct node
{
    int l, r;
    int maxn, sum;
};
node tr[N << 6];
int cnt;
int rt[N];
void pushup(int rt)
{
    if (tr[tr[rt].l].sum >= tr[tr[rt].r].sum)
    {
        tr[rt].sum = tr[tr[rt].l].sum;
        tr[rt].maxn = tr[tr[rt].l].maxn;
    }
    else
    {
        tr[rt].sum = tr[tr[rt].r].sum;
        tr[rt].maxn = tr[tr[rt].r].maxn;
    }
}
void update(int &rt, int l, int r, int v, int val)
{
    if (!rt)
        rt = ++cnt;
    if (l == r)
    {
        tr[rt].sum += val;
        tr[rt].maxn = v;
        return;
    }
    int m = (l + r) >> 1;
    if (v <= m)
        update(tr[rt].l, l, m, v, val);
    else if (v > m)
        update(tr[rt].r, m + 1, r, v, val);
    pushup(rt);
}
void merge(int &lt, int rt, int l, int r)
{
    if (!lt || !rt)
    {
        lt += rt;
        return;
    }
    if (l == r)
    {
        tr[lt].sum += tr[rt].sum;
        return;
    }
    int m = (l + r) >> 1;
    merge(tr[lt].l, tr[rt].l, l, m);
    merge(tr[lt].r, tr[rt].r, m + 1, r);
    pushup(lt);
}
int ans[N];
void solve(int u, int fa)
{
    for (auto i : G[u])
        if (i != fa)
        {
            solve(i, u);
            merge(rt[u], rt[i], 1, 1e5);
        }
    ans[u] = tr[rt[u]].maxn;
    if (!tr[rt[u]].sum)
        ans[u] = 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    init_lca();
    for (int i = 1; i <= m; ++i)
    {
        int c;
        scanf("%d%d%d", &u, &v, &c);
        int lca = get_lca(u, v);
        update(rt[u], 1, 1e5, c, 1);
        update(rt[v], 1, 1e5, c, 1);
        update(rt[lca], 1, 1e5, c, -1);
        update(rt[f[lca][0]], 1, 1e5, c, -1);
    }
    solve(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}