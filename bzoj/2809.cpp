#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct Litree
{
    int ls[N], rs[N];
    int val[N], dis[N];
    int tot;
    int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (val[x] < val[y])
            swap(x, y);
        rs[x] = merge(rs[x], y);
        if (dis[rs[x]] > dis[ls[x]])
            swap(ls[x], rs[x]);
        dis[x] = rs[x] == 0 ? 0 : dis[rs[x]] + 1;
        return x;
    }
    int push(int x, int v)
    {
        ls[++tot] = rs[tot] = dis[tot] = 0;
        val[tot] = v;
        return merge(tot, x);
    }
    int pop(int x)
    {
        int l = ls[x], r = rs[x];
        ls[x] = rs[x] = dis[x] = 0;
        val[x] = -0x3f3f3f3f;
        return merge(l, r);
    }
    void init(int n)
    {
        memset(ls, 0, sizeof(ls[0]) * (n + 1));
        memset(rs, 0, sizeof(rs[0]) * (n + 1));
        memset(dis, 0, sizeof(dis[0]) * (n + 1));
    }
    int build(int n)
    {
        init(n);
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        while (q.size() > 1)
        {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
            q.push(merge(x, y));
        }
        return q.front();
    }
};
Litree tr;
ll n, m, cnt[N];
vector<int> G[N];
ll c[N], l[N];
int sz[N], rt[N];
ll ans = 0;
void dfs(int u, int fa)
{
    cnt[u] += c[u];
    sz[u] = 1;
    rt[u] = tr.push(rt[u], c[u]);
    for (int it = 0; it < G[u].size(); ++it)
    {
        int i = G[u][it];
        if (i != fa)
        {
            dfs(i, u);
            cnt[u] += cnt[i];
            sz[u] += sz[i];
            rt[u] = tr.merge(rt[u], rt[i]);
        }
    }
    while (cnt[u] > m)
    {
        int v = tr.val[rt[u]];
        rt[u] = tr.pop(rt[u]);
        cnt[u] -= v;
        --sz[u];
    }
    ans = max(ans, sz[u] * l[u]);
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int b;
        scanf("%d%lld%lld", &b, &c[i], &l[i]);
        G[b].push_back(i);
        G[i].push_back(b);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}