#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int g[N], p[N], sz[N], h[N], cntg[N];
bool f;
void dfs(int u, int fa)
{
    sz[u] = p[u];
    for (auto i : G[u])
        if (i != fa && !f)
        {
            dfs(i, u);
            sz[u] += sz[i];
            cntg[u] += cntg[i];
        }
    g[u] = (h[u] + sz[u]) / 2;
    if ((h[u] + sz[u]) / 2 || g[u] < 0 || g[u] > sz[u] || cntg[u] > g[u])
    {
        f = 1;
        return;
    }
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
            cntg[i] = 0;
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
        dfs(1, 0);
        puts(f ? "No" : "Yes");
    }
    return 0;
}