#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef unsigned int uint;
typedef long long ll;
uint s;
uint gets(uint x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x;
}
vector<int> G[N];
int dep[N], son[N], f[N][19];  //结点深度，重儿子，父亲节点
int maxdep[N], top[N], len[N]; //重链最大深度， 重链顶结点，重链长度
void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    maxdep[u] = dep[u];
    for (auto i : G[u])
        if (i != fa)
        {
            dfs1(i, u);
            if (maxdep[i] > maxdep[son[u]])
            {
                son[u] = i;
                maxdep[u] = maxdep[i];
            }
        }
}
void dfs2(int u, int t)
{
    top[u] = t;
    len[u] = maxdep[u] - dep[top[u]] + 1;
    if (son[u])
        dfs2(son[u], t);
    for (auto i : G[u])
        if (i != son[u] && i != f[u][0])
            dfs2(i, i);
}
vector<int> us[N], ds[N];
int hbit[N];
int n, q;
void init()
{
    int cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (i >= (1 << cur))
            ++cur;
        hbit[i] = cur - 1;
    }
}
int query(int u, int k)
{
    if (k > dep[u])
        return 0;
    if (!k)
        return u;
    u = f[u][hbit[k]];
    k ^= (1 << hbit[k]);
    if (!k)
        return u;
    else if (dep[u] - dep[top[u]] > k)
        return ds[top[u]][dep[u] - dep[top[u]] - k];
    return us[top[u]][k - dep[u] + dep[top[u]]];
}
int main()
{
    scanf("%d%d%u", &n, &q, &s);
    init();
    int root = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &f[i][0]);
        if (!f[i][0])
            root = i;
        else
        {
            G[f[i][0]].push_back(i);
            G[i].push_back(f[i][0]);
        }
    }
    for (int i = 1; i < 19; ++i)
        for (int j = 1; j <= n; ++j)
            f[j][i] = f[f[j][i - 1]][i - 1];
    dfs1(root, 0);
    dfs2(root, root);
    for (int i = 1; i <= n; ++i)
        if (top[i] == i)
        {
            int l = 0, x = i;
            while (l < len[i] && x)
            {
                us[i].push_back(x);
                x = f[x][0], ++l;
            }
            l = 0, x = i;
            while (l < len[i])
            {
                ds[i].push_back(x);
                x = son[x], ++l;
            }
        }
    int ans = 0, u, k;
    ll sum = 0;
    for (int i = 1; i <= q; ++i)
    {
        u = (gets(s) ^ ans) % n + 1;
        k = (gets(s) ^ ans) % dep[u];
        int cur = query(u, k);
        sum ^= 1ll * i * cur;
        ans = cur;
    }
    printf("%lld\n", sum);
    return 0;
}