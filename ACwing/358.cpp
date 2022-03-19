#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
struct edge
{
    int to;
    ll w;
    edge() {}
    edge(int _to, ll _w) : to(_to), w(_w) {}
};
vector<edge> G[N];
bool vis[N];
int blk[N];
void bfs(int u, int t)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        if (vis[cur])
            continue;
        vis[cur] = 1;
        blk[cur] = t;
        for (auto i : G[cur])
            q.push(i.to);
    }
}
int in[N], n;
ll d[N], f[N];
// d[x], x-th component max in-tree longest path.
// f[x], x as root, max length of subtree to root.
void topo() // find circle
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 1)
            q.push(i);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        for (auto i : G[cur])
            if (in[i.to] > 1)
            {
                d[blk[i.to]] = max(d[blk[i.to]], f[i.to] + f[cur] + i.w);
                f[i.to] = max(f[i.to], f[cur] + i.w);
                if ((--in[i.to]) == 1)
                    q.push(i.to);
            }
    }
}
int c[N << 1];
ll w[N << 1], res;
void dp(int u, int t)
{
    res = 0;
    int m = 0, v = u;
    while (in[v] > 1)
    {
        c[++m] = v;
        in[v] = 1;
        for (auto i : G[v])
            if (in[i.to] > 1)
            {
                v = i.to;
                w[m + 1] = w[m] + i.w;
                break;
            }
    }
    if (m == 2)
    {
        for (auto i : G[v])
            if (i.to == u)
                d[t] = max(d[t], f[u] + f[v] + i.w);
        return;
    }
    for (auto i : G[v])
        if (i.to == u)
        {
            w[m + 1] = w[m] + i.w;
            break;
        }
    for (int i = 1; i < m; ++i)
    {
        c[m + i] = c[i];
        w[m + i] = w[m + 1] + w[i];
    }
    deque<int> q;
    q.push_back(1);
    for (int i = 2; i < 2 * m; ++i)
    {
        while (q.front() <= i - m)
            q.pop_front();
        d[t] = max(d[t], f[c[q.front()]] - w[q.front()] + f[c[i]] + w[i]);
        while (q.size() && f[c[q.back()]] - w[q.back()] < f[c[i]] - w[i])
            q.pop_back();
        q.push_back(i);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int v;
        ll w;
        scanf("%d%lld", &v, &w);
        G[i].push_back({v, w});
        G[v].push_back({i, w});
        ++in[i];
        ++in[v];
    }
    int t = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            bfs(i, ++t);
    ll ans = 0;
    topo();
    for (int i = 1; i <= n; ++i)
        if (in[i] > 1)
        {
            dp(i, blk[i]);
            ans += d[blk[i]];
        }
    printf("%lld\n", ans);
    return 0;
}