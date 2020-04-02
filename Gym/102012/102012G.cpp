#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
const ll mod = 1e9 + 7;
vector<int> G[N];
int f[N][20];
int lca_sum[N], sum[N];
int dep[N];
ll fac[N], inv[N];
void get_sum(int fa, int u)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (auto i : G[u])
        if (i != fa)
            get_sum(u, i);
}
void init_lca(int n)
{
    get_sum(0, 1);
    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= n; ++i)
            f[i][j] = f[f[i][j - 1]][j - 1];
}
int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; ~i; --i)
        if ((dep[u] - dep[v]) & (1 << i))
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 19; ~i; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
void dfs(int fa, int u)
{
    for (auto i : G[u])
        if (i != fa)
        {
            dfs(u, i);
            sum[u] += sum[i];
        }
}
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void get_fac()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = pow(fac[N - 1], mod - 2, mod);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        G[i].clear();
        sum[i] = 0;
        lca_sum[i] = 0;
        dep[i] = 0;
        for (int j = 0; j < 20; ++j)
            f[i][j] = 0;
    }
}
ll c(int m, int n)
{
    if (n == 0 || m == n)
        return 1;
    if (n < 0 || m < 0 || m < n)
        return 0;
    return fac[m] * inv[m - n] % mod * inv[n] % mod;
}
int main()
{
    get_fac();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        init(n);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        init_lca(n);
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ++sum[u], ++sum[v];
            int lca = get_lca(u, v);
            --sum[lca], --sum[f[lca][0]];
            ++lca_sum[lca];
        }
        dfs(0, 1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = (ans + (c(sum[i], k) - c(sum[i] - lca_sum[i], k) + mod) % mod) % mod;
        assert(ans >= 0);
        printf("%lld\n", ans);
    }
    return 0;
}