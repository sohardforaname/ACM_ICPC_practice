#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int a[N], b[N], p[N], sz[N], h[N];
bool f;
void pre(int u, int fa)
{
    sz[u] = p[u];
    for (auto i : G[u])
        if (i != fa)
        {
            pre(i, u);
            sz[u] += sz[i];
        }
}
void dfs(int u, int fa)
{
    int size = sz[u];
    if (h[u] >= 0)
        a[u] += h[u];
    else
        b[u] -= h[u];
    size -= h[u];
    if (size < 0 || size % 2)
    {
        f = 1;
        return;
    }
    a[u] += size / 2;
    b[u] += size / 2;
    for (auto i : G[u])
    {
        if (f)
            return;
        if (i != fa)
            dfs(i, u);
    }
}
void check(int u, int fa)
{
    if (f)
        return;
    if (sz[u] != a[u] + b[u])
    {
        f = 1;
        return;
    }
    for (auto i : G[u])
        if (i != fa)
            check(i, u);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        f = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            G[i].clear();
            a[i] = b[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &h[i]);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        pre(1, 0);
        dfs(1, 0);
        check(1, 0);
        puts(f ? "No" : "Yes");
    }
    return 0;
}