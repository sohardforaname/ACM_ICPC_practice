#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
typedef pair<int, int> edge;
vector<edge> G[N];
int dfn[N], low[N], clk;
stack<int> s;
bool vis[N];
int c[N], scc_cnt;
int n, m, ss;
ll tab[N / 10], sum[N / 10];
void init()
{
    for (int i = 1; i < 1e5; ++i)
        tab[i] = tab[i - 1] + i;
    memcpy(sum, tab, sizeof(tab));
    for (int i = 1; i < 1e5; ++i)
        sum[i] += sum[i - 1];
}
ll calc(ll x)
{
    int pos = upper_bound(tab, tab + (ll)1e5, x) - tab;
    return pos * x - sum[pos - 1];
}
void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++clk;
    s.push(u), vis[u] = 1;
    for (auto e : G[u])
    {
        int i = e.first;
        if (!dfn[i])
        {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
        }
        else if (vis[i])
            low[u] = min(low[u], dfn[i]);
    }
    if (dfn[u] == low[u])
    {
        ++scc_cnt;
        int y;
        do
        {
            y = s.top();
            s.pop();
            vis[y] = 0;
            c[y] = scc_cnt;
        } while (u ^ y);
    }
}
void tarjan()
{
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            dfs(i, 0);
}
ll w[N];
vector<edge> sG[N];
ll f[N];
ll dfsw(int u, int fa)
{
    if (f[u])
        return f[u];
    f[u] = w[u];
    ll tmp = 0;
    for (auto i : sG[u])
        tmp = max(tmp, 1ll * i.second + dfsw(i.first, u));
    return f[u] += tmp;
}
int main()
{
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, cost;
        scanf("%d%d%d", &u, &v, &cost);
        G[u].push_back({v, cost});
    }
    scanf("%d", &ss);
    tarjan();
    for (int i = 1; i <= n; ++i)
        for (auto j : G[i])
        {
            if (c[i] != c[j.first])
                sG[c[i]].push_back({c[j.first], j.second});
            else
                w[c[i]] += calc(j.second);
        }
    printf("%lld\n", dfsw(c[ss], 0));
    return 0;
}