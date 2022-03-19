#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct edge
{
    int v, c;
    edge() {}
    edge(int _v, int _c) : v(_v), c(_c) {}
    bool operator<(const edge &a) const
    {
        return c > a.c;
    }
};
vector<edge> G[N << 4];
int dis[N << 4];
bool vis[N << 4];
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<edge> q;
    q.push({s, 0});
    dis[s] = 0;
    while (q.size())
    {
        edge now = q.top();
        q.pop();
        if (vis[now.v])
            continue;
        vis[now.v] = 1;
        for (auto i : G[now.v])
            if (dis[i.v] > dis[now.v] + i.c)
            {
                dis[i.v] = dis[now.v] + i.c;
                q.push({i.v, dis[i.v]});
            }
    }
}
int main()
{
    int n, m, k, s, t;
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        for (int j = 0; j <= k; ++j)
        {
            G[u + j * n].push_back({v + j * n, w});
            G[v + j * n].push_back({u + j * n, w});
        }
    }
    for (int i = 0; i < k * n; ++i)
    {
        int size = G[i].size();
        for (int j = 0; j < size; ++j)
            G[i].push_back({G[i][j].v + n, 0});
    }
    dijkstra(s);
    int minn = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i)
        minn = min(minn, dis[i * n + t]);
    printf("%d\n", minn);
    return 0;
}