#include "../base.h"

const int N = 3e3 + 5;
bool multi = 0;

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
int n, m;
ll dis[N], into[N], arri[N];
bool vis[N];
vector<int> pG[N];
int in[N];
void dijkstra(int s)
{
    fill(arri + 1, arri + n + 1, 1e18);
    fill(vis + 1, vis + n + 1, 0);
    priority_queue<edge> q;
    q.push({s, 0});
    arri[s] = 0;
    while (q.size())
    {
        int u = q.top().to;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : G[u])
            if (arri[i.to] > dis[u] + i.w)
            {
                arri[i.to] = dis[u] + i.w;
                if (!in[i.to])
                {
                    dis[i.to] = max(into[i.to], arri[i.to]);
                    q.push({i.to, dis[i.to]});
                }
            }
        for (auto i : pG[u])
        {
            into[i] = max(into[i], dis[u]); //v受到u保护
            if (!--in[i])
            {
                dis[i] = max(arri[i], into[i]);
                q.push({i, dis[i]});
            }
        }
    }
}

void solve()
{
    io(n, m);
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        io(u, v, w);
        G[u].push_back({v, w});
    }
    for (int i = 1; i <= n; ++i)
    {
        io(u);
        for (int j = 0; j < u; ++j)
        {
            io(v);
            pG[v].push_back(i);
            ++in[i];
        }
    }
    dijkstra(1);
    io(dis[n], '\n');
}

int main()
{
    int t;
    if (multi)
        io(t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}