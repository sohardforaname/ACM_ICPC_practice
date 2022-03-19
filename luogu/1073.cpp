#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
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
int w[N];
vector<edge> G[N];
int dis[N];
bool vis[N];
void spfa()
{
    queue<int> q;
    for (int i = 0; i < N; ++i)
        dis[i] = -0x3f3f3f3f;
    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (auto i : G[now])
            if (dis[i.v] < dis[now] + i.w)
            {
                dis[i.v] = dis[now] + i.w;
                if (!vis[i.v])
                {
                    q.push(i.v);
                    vis[i.v] = 1;
                }
            }
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, z;
        scanf("%d%d%d", &u, &v, &z);
        for (int j = 0; j <= 2; ++j)
        {
            G[u + j * n].push_back({v + j * n, 0});
            if (z == 2)
                G[v + j * n].push_back({u + j * n, 0});
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int size = G[i].size();
        for (int j = 0; j < size; ++j)
        {
            G[i].push_back({G[i][j].v + n, -w[G[i][j].v]});
            G[i + n].push_back({G[i][j].v + 2 * n, w[G[i][j].v]});
        }
    }
    spfa();
    printf("%d\n", dis[n * 3] > 0 ? dis[n * 3] : 0);
    return 0;
}