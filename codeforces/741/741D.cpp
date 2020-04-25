#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> G[N];
int ans[N], maxdep[(1 << 22) + 5];
int w[N], pre[N];
int dep[N], sz[N], son[N];
int dfn[N], low[N], clk;
int id[N];
void dfs1(int u, int fa)
{
    sz[u] = 1;
    dep[u] = dep[fa] + 1;
    dfn[u] = ++clk;
    id[clk] = u;
    for (auto i : G[u])
    {
        pre[i] = pre[u] ^ w[i];
        dfs1(i, u);
        sz[u] += sz[i];
        if (sz[i] > sz[son[u]])
            son[u] = i;
    }
    low[u] = clk;
}
void add(int u, int rt, int op)
{
    if (op == 1)
    {
        if (maxdep[pre[u]])
            ans[rt] = max(ans[rt], maxdep[pre[u]] + dep[u] - 2 * dep[rt]);
        for (int i = 0; i < 22; ++i)
            if (maxdep[pre[u] ^ (1 << i)])
                ans[rt] = max(ans[rt], maxdep[pre[u] ^ (1 << i)] + dep[u] - 2 * dep[rt]);
    }
    else
        maxdep[pre[u]] = 0;
    for (auto i : G[u])
        add(i, rt, op);
}
void upd(int u)
{
    maxdep[pre[u]] = max(maxdep[pre[u]], dep[u]);
    for (auto i : G[u])
        upd(i);
}
void dfs2(int u, int op)
{
    for (auto i : G[u])
        if (i != son[u])
            dfs2(i, 0);
    if (son[u])
        dfs2(son[u], 1);
    for (auto i : G[u])
        ans[u] = max(ans[u], ans[i]);
    if (maxdep[pre[u]])
        ans[u] = max(ans[u], maxdep[pre[u]] - dep[u]);
    for (int i = 0; i < 22; ++i)
        if (maxdep[pre[u] ^ (1 << i)])
            ans[u] = max(ans[u], maxdep[pre[u] ^ (1 << i)] - dep[u]);
    maxdep[pre[u]] = max(maxdep[pre[u]], dep[u]);
    for (auto i : G[u])
        if (i != son[u])
        {
            add(i, u, 1);
            upd(i);
        }
    if (!op)
        add(u, u, 0);
}
int main()
{
    int n;
    char c[2];
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        int fa;
        scanf("%d%s", &fa, c);
        w[i] = 1 << (c[0] - 'a');
        G[fa].push_back(i);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}