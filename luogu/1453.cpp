#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 2e9;
int dp[N], gs[N], s[N];
vector<int> G[N];
int lt, rt;
int n, w[N];
void dfs(int u, int fa)
{
    dp[u] = 0, s[u] = 0, gs[u] = 0;
    for (auto i : G[u])
    {
        if (i == fa)
            continue;
        dfs(i, u);
        s[u] += dp[i];
        gs[fa] += dp[i];
    }
    dp[u] = max(s[u], gs[u] + w[u]);
}
int fa[N];
int find(int u)
{
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}
void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
}
int main()
{
    int n;
    double k;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ++u, ++v;
        if (find(u) != find(v))
        {
            G[u].push_back(v);
            G[v].push_back(u);
            join(u, v);
        }
        else
            lt = u, rt = v;
    }
    scanf("%lf", &k);
    int ans = 0;

    int tmp = w[rt];
    w[rt] = -inf;
    dfs(lt, 0);
    ans = max(ans, dp[lt]);
    w[rt] = tmp;

    tmp = w[lt];
    w[lt] = -inf;
    dfs(rt, 0);
    ans = max(ans, dp[rt]);

    printf("%.1f", ans * 1.0 * k);
    return 0;
}
