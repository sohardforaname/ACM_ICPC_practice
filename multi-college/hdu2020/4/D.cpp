#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 4e5 + 5;
int head[N], nxt[M << 1];
typedef long long ll;
struct edge
{
    ll to, w;
    edge(ll _to, ll _w) : to(_to), w(_w) {}
    edge() {}
    bool operator<(const edge &a) const
    {
        return w > a.w;
    }
};
int vcnt, ecnt;
int n, m, s, t;
vector<edge> G[N];
ll x;
ll dis[N];
bool vis[N];
priority_queue<edge> q;
void djikstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push({s, 0});
    while (q.size())
    {
        edge cur = q.top();
        q.pop();
        if (vis[cur.to])
            continue;
        vis[cur.to] = 1;
        for (auto i : G[cur.to])
            if (dis[i.to] > dis[cur.to] + i.w)
            {
                dis[i.to] = dis[cur.to] + i.w;
                q.push({i.to, dis[i.to]});
            }
    }
}
char id[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d%lld", &n, &m, &s, &t, &x);
        for (int i = 1; i <= n * 2; ++i)
            G[i].clear();
        scanf("%s", id + 1);
        for (int i = 1; i <= m; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }
}