#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 2e1 + 5;
struct edge
{
    int to;
    ll w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
};

vector<edge> G[M];

bool vis[M];
ll dis[M];
priority_queue<edge> q;
void dijkstra(int s)
{
    fill(dis + 1, dis + M, 1e9);
    dis[s] = 0;
    q.push({s, 0});
    while (q.size())
    {
        int u = q.top().to;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : G[u])
            if (dis[i.to] > dis[u] + i.w)
            {
                dis[i.to] = dis[u] + i.w;
                q.push({i.to, dis[i.to]});
            }
    }
}

ll dp[N];
bool notgo[M][N];
ll day[N][N];

int main()
{
    int n, m, k, e;
    scanf("%d%d%d%d", &n, &m, &k, &e);
    for (int i = 1; i <= e; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int d;
    scanf("%d", &d);
    for (int i = 1; i <= d; ++i)
    {
        int p, a, b;
        scanf("%d%d%d", &p, &a, &b);
        for (int j = a; j <= b; ++j)
            notgo[p][j] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
        {
            memset(vis, 0, sizeof(vis));
            for (int k = 1; k <= m; ++k)
                for (int l = i; l <= j; ++l)
                    if (notgo[k][l])
                        vis[k] = 1;
            dijkstra(1);
            day[i][j] = dis[m];
        }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = day[1][i] * i;
        for (int j = 1; j < i; ++j)
            dp[i] = min(dp[i], dp[j] + day[j + 1][i] * (i - j) + k);
    }
    printf("%lld\n", dp[n]);
    return 0;
}