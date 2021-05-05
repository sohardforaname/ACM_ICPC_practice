#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct edge {
    int to;
    ll w;
    bool operator<(const edge& e) const
    {
        return w > e.w;
    }
};
vector<edge> G[N];
ll dis[N];
bool vis[N];
int n, m;
void dijkstra(int s)
{
    fill(dis + 1, dis + n + 1, (1ll << 31) - 1);
    fill(vis + 1, vis + n + 1, 0);
    priority_queue<edge> q;
    q.push({ s, 0 });
    dis[s] = 0;
    while (q.size()) {
        edge e = q.top();
        q.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (auto i : G[e.to])
            if (dis[i.to] > dis[e.to] + i.w) {
                dis[i.to] = dis[e.to] + i.w;
                q.push({ i.to, dis[i.to] });
            }
    }
}

int main()
{
    int s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({ v, w });
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i)
        printf("%lld%c", dis[i], " \n"[i == n]);
    return 0;
}