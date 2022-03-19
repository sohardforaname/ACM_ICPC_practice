#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int K = 5e1 + 5;
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
vector<edge> G[N], G1[N];
int n, m, k;
ll mod;
ll dis[N], dis1[N];
bool vis[N];

void addm(ll &a, ll b)
{
    a += b;
    (a >= mod) && (a -= mod);
}

void dijkstra(int s, vector<edge> *G, ll *dis)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 1));
    memset(vis, 0, sizeof(vis));
    priority_queue<edge> q;
    dis[s] = 0;
    q.push({s, 0});
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
                q.push({i.to, dis[i.to]});
            }
    }
}

bool eflag[N];
int in[N], id[N], cnt;
bool toposort()
{
    queue<int> q;
    for (int u = 1; u <= n; ++u)
        for (auto j : G[u])
            if (j.w == 0)
                ++in[j.to], eflag[u] = eflag[j.to] = 1;
    for (int i = 1; i <= n; ++i)
        if (eflag[i] && !in[i])
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        id[u] = ++cnt;
        for (auto i : G[u])
            if (i.w == 0)
            {
                --in[i.to];
                if (!in[i.to])
                    q.push(i.to);
            }
    }
    for (int i = 1; i <= n; ++i)
        if (eflag[i] && in[i] && dis[i] + dis1[i] <= dis[n] + k)
            return true;
    return false;
}

ll dp[N][K];
int ver[N];

ll cal()
{
    for (int i = 1; i <= n; ++i)
        ver[i] = i;
    sort(ver + 1, ver + n + 1, [](const int &a, const int &b) -> bool {
        return dis[a] == dis[b] ? id[a] < id[b] : dis[a] < dis[b];
    });

    dp[1][0] = 1;
    for (int k1 = 0; k1 <= k; ++k1)
        for (int i = 1; i <= n; ++i)
        {
            int u = ver[i];
            if (dp[u][k1])
                for (auto &j : G[u])
                {
                    int v = j.to;
                    ll d = dis[u] + j.w - dis[v] + k1;
                    if (d <= k)
                        addm(dp[v][d], dp[u][k1]);
                }
        }
    ll ans = 0;
    for (int i = 0; i <= k; ++i)
        addm(ans, dp[n][i]);
    return ans;
}

void init(int n, int k)
{
    for (int i = 1; i <= n; ++i)
    {
        G[i].clear();
        G1[i].clear();
    }
    memset(eflag, 0, sizeof(eflag));
    memset(in, 0, sizeof(in));
    memset(dp, 0, sizeof(dp));
}

int main()
{
    freopen("D:\\firefox\\P3953_6.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%lld", &n, &m, &k, &mod);
        init(n, k);
        for (int i = 1; i <= m; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G1[v].push_back({u, w});
        }
        dijkstra(1, G, dis);
        dijkstra(n, G1, dis1);
        if (toposort())
            printf("-1\n");
        else
            printf("%lld\n", cal());
    }
    return 0;
}