#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int son[N], sz[N], dep[N];
vector<int> s[N << 1];
vector<pair<int, int>> q[N];
int ans[N];
bool vis[N];
int f[N][20];
void init(int n)
{
    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= n; ++i)
            f[i][j] = f[f[i][j - 1]][j - 1];
}
int getanc(int u, int p)
{
    for (int i = 19; ~i; --i)
        if ((1 << i) & p)
            u = f[u][i];
    return u;
}
void dfs1(int u, int fa)
{
    sz[u] = 1;
    if (u)
        dep[u] = dep[fa] + 1;
    for (auto i : G[u])
        if (i != fa)
        {
            dfs1(i, u);
            sz[u] += sz[i];
            if (sz[i] > sz[son[u]])
                son[u] = i;
        }
}
void add(int u, int fa, int op)
{
    if (op == 1)
        s[dep[u]].push_back(u);
    else
        s[dep[u]].clear();
    for (auto i : G[u])
        if (i != fa && !vis[i])
            add(i, u, op);
}
void dfs2(int u, int fa, int op)
{
    for (auto i : G[u])
        if (i != fa && i != son[u])
            dfs2(i, u, 0);
    if (son[u])
        dfs2(son[u], u, 1), vis[son[u]] = 1;
    add(u, fa, 1);
    for (auto i : q[u])
        ans[i.first] = s[dep[u] + i.second].size();
    if (son[u])
        vis[son[u]] = 0;
    if (!op)
        add(u, fa, 0);
}
int main()
{
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        f[i][0] = a;
        G[a].push_back(i);
        G[i].push_back(a);
    }
    init(n);
    dfs1(0, 0);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (dep[x] - y <= 0)
            ans[i] = 1;
        else
            q[getanc(x, y)].push_back({i, y});
    }
    dfs2(0, 0, 0);
    for (int i = 1; i <= m; ++i)
        printf("%d%c", ans[i] - 1, " \n"[i == m]);
    return 0;
}