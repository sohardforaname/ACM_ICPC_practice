#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
typedef long long ll;
int f[N][20];
ll d[N][20][62];
vector<int> G[N];
ll val[N];
int dep[N];
int n, q;
void add(ll x, ll *d)
{
    for (int i = 61; ~i && x; --i)
    {
        if (x & (1ll << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                break;
            }
        }
    }
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    add(val[u], d[u][0]);
    f[u][0] = fa;
    for (auto i : G[u])
        if (i != fa)
            dfs(i, u);
}
void merge(ll *d1, ll *d2)
{
    for (int i = 0; i <= 61; ++i)
        if (d2[i])
            add(d2[i], d1);
}
void init_lca()
{
    for (int i = 1; i <= 19; ++i)
        for (int j = 1; j <= n; ++j)
        {
            f[j][i] = f[f[j][i - 1]][i - 1];
            merge(d[j][i], d[f[j][i - 1]][i - 1]);
            merge(d[j][i], d[j][i - 1]);
        }
}
ll ans[62];
void get_ans(int x, int y)
{
    memset(ans, 0, sizeof(ans));
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; ~i; --i)
        if ((dep[x] - dep[y]) & (1 << i))
        {
            merge(ans, d[x][i]);
            x = f[x][i];
        }
    if (x == y)
    {
        merge(ans, d[x][0]);
        return;
    }
    for (int i = 19; ~i; --i)
        if (f[x][i] != f[y][i])
        {
            merge(ans, d[x][i]);
            merge(ans, d[y][i]);
            x = f[x][i], y = f[y][i];
        }
    merge(ans, d[x][0]);
    merge(ans, d[y][0]);
    merge(ans, d[f[x][0]][0]);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    init_lca();
    for (int i = 1; i <= q; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        get_ans(u, v);
        ll res = 0;
        for (int i = 61; ~i; --i)
            if (ans[i] && (res ^ ans[i]) > res)
                res ^= ans[i];
        printf("%lld\n", res);
    }
    return 0;
}