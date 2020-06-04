#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
struct edge
{
    int v, w;
    edge() {}
    edge(int _v, int _w) : v(_v), w(_w) {}
    bool operator<(const edge &a) const
    {
        return w > a.w;
    }
};
vector<edge> G[N << 6];
int dis[N << 6];
bool vis[N << 6];
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<edge> q;
    q.push({0, 0});
    dis[0] = 0;
    while (q.size())
    {
        edge now = q.top();
        q.pop();
        if (vis[now.v])
            continue;
        vis[now.v] = 1;
        for (auto i : G[now.v])
            if (dis[i.v] > dis[now.v] + i.w)
            {
                dis[i.v] = dis[now.v] + i.w;
                q.push({i.v, dis[i.v]});
            }
    }
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
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
            G[i].push_back({G[i][j].v + n, G[i][j].w / 2});
    }
    dijkstra();
    int minn = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i)
        minn = min(minn, dis[n - 1 + i * n]);
    printf("%d\n", minn);
    return 0;
}