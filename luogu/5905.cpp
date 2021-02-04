#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct edge
{
    int to;
    ll w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
};
vector<edge> G[N];

bool vis[N];
ll h[N], dis[N];
int inq[N];
int n, m;
int spfa(int s)
{
    memset(h, 0x3f, sizeof(h));
    memset(vis, 0, sizeof(vis));
    memset(inq, 0, sizeof(inq));
    queue<int> q;
    q.push(s);
    h[s] = 0;
    vis[s] = 1;
    ++inq[s];
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto &i : G[u])
            if (h[i.to] > h[u] + i.w)
            {
                h[i.to] = h[u] + i.w;
                if (!vis[i.to])
                {
                    vis[i.to] = 1;
                    q.push(i.to);
                    if ((++inq[i.to]) == n)
                        return 0;
                }
            }
    }
    return 1;
}

void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<edge> q;
    q.push({s, 0});
    dis[s] = 0;
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (auto &i : G[e.to])
            if (dis[i.to] > dis[e.to] + i.w)
            {
                dis[i.to] = dis[e.to] + i.w;
                q.push({i.to, dis[i.to]});
            }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
    }
    for (int i = 1; i <= n; ++i)
        G[0].push_back({i, 0});
    if (!spfa(0))
        return printf("-1\n"), 0;
    for (int i = 1; i <= n; ++i)
        for (auto &j : G[i])
            j.w += h[i] - h[j.to];
    for (int i = 1; i <= n; ++i)
    {
        dijkstra(i);
        ll ans = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (INF == dis[j])
                ans += 1e9 * j;
            else
                ans += (dis[j] - h[i] + h[j]) * j;
        }
        printf("%lld\n", ans);
    }
    return 0;
}