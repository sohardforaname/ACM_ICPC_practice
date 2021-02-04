#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
struct edge
{
    int to, w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
};
vector<edge> G1[N];
vector<edge> G2[N];

int dis1[N], dis2[N];
bool vis[N];
int n, m;

priority_queue<edge> q;
void dijkstra(const vector<edge> *G, int *dis)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    memset(vis, 0, sizeof(vis[0]) * (n + 2));
    q.push({1, 0});
    dis[1] = 0;
    while (q.size())
    {
        auto e = q.top();
        q.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (auto i : G[e.to])
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
        G1[u].push_back({v, w});
        G2[v].push_back({u, w});
    }
    int ans = 0;
    dijkstra(G1, dis1);
    for (int i = 2; i <= n; ++i)
        ans += dis1[i];
    dijkstra(G2, dis2);
    for (int i = 2; i <= n; ++i)
        ans += dis2[i];
    printf("%d\n", ans);
    return 0;
}