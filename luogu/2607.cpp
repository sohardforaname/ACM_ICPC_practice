#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
ll inf = -2e9;
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
int head[N << 1], nxt[N << 1], ver[N << 1], tot;
ll w[N];
vector<pair<int, int>> cyc;
ll dp[N], s[N], gs[N];
void add(int u, int v)
{
    nxt[++tot] = head[u];
    head[u] = tot;
    ver[tot] = v;
}
void dfs(int u, int fa)
{
    dp[u] = s[u] = gs[u] = 0;
    for (int j = head[u]; j; j = nxt[j])
    {
        int i = ver[j];
        if (i == fa)
            continue;
        dfs(i, u);
        s[u] += dp[i];
        gs[fa] += dp[i];
    }
    dp[u] = max(s[u], gs[u] + w[u]);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        int u;
        scanf("%lld%d", &w[i], &u);
        if (find(i) != find(u))
        {
            join(i, u);
            add(i, u);
            add(u, i);
        }
        else
            cyc.push_back({i, u});
    }
    ll ans = 0;
    for (auto &i : cyc)
    {
        ll tmp = 0;
        swap(inf, w[i.first]);
        dfs(i.second, 0);
        tmp = max(tmp, dp[i.second]);
        swap(inf, w[i.first]);
        swap(inf, w[i.second]);
        dfs(i.first, 0);
        tmp = max(tmp, dp[i.first]);
        swap(inf, w[i.second]);
        ans += tmp;
    }
    printf("%lld\n", ans);
    return 0;
}