#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge
{
    int to;
    ll w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
};
const int N = 5e5 + 5;
vector<edge> G[N];

ll dis[N];
int pre[N];
bool vis[N];

int n, t;
void dijkstra(int s)
{
    priority_queue<edge> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push({s, 0});
    dis[s] = 0;
    while (q.size())
    {
        auto u = q.top().to;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : G[u])
            if (dis[i.to] > dis[u] + i.w)
            {
                dis[i.to] = dis[u] + i.w;
                pre[i.to] = u;
                q.push({i.to, dis[i.to]});
            }
    }
}

int mp[105][105];
int cal(int x, int y, int z)
{
    return (z - 1) * n * n + (x - 1) * n + y;
}
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool check(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= n;
}
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &mp[i][j]);
    for (int l = 1; l <= 3; ++l)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (check(x, y))
                        G[cal(i, j, l)].push_back({cal(x, y, l + 1), t});
                }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            G[cal(i, j, 4)].push_back({cal(i, j, 1), mp[i][j]});
    dijkstra(cal(1, 1, 1));
    printf("%lld\n", min({dis[cal(n, n, 1)], dis[cal(n, n, 2)], dis[cal(n, n, 3)]}));
    return 0;
}