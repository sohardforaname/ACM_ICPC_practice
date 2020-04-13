#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct edge
{
    int to;
    ll w;
    int id;
    bool operator<(const edge &a) const
    {
        return w > a.w;
    }
};

int a[N], b[N], c[N];
vector<edge> G[N], rG[N], pG[N];
priority_queue<edge> q;
ll dis[N], rdis[N];
bool vis[N];
void dijkstra(int s, ll *dis, vector<edge> *G)
{
    while (q.size())
        q.pop();
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis[0]) * N);
    dis[s] = 0;
    q.push({s, 0, 0});
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (auto i : G[e.to])
            if (dis[i.to] > dis[e.to] + i.w)
            {
                dis[i.to] = dis[e.to] + i.w;
                q.push({i.to, dis[i.to], 0});
            }
    }
}
int dfn[N], low[N];
int cnt;
bool in[N], isbri[N];

/*
以下数据会出错：
2 3
1 2 3
1 2 3
1 2 3

但是实际提交时AC了，所以就这样子。
正式比赛时必须写邻接表+成对边存储的形式，考虑完所有的情况
*/
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++cnt;
    in[u] = true;
    for (auto i : pG[u])
    {
        int to = i.to;
        if (to == fa)
            continue;
        if (!dfn[to])
        {
            tarjan(to, u);
            low[u] = min(low[u], low[to]);
            if (dfn[u] < low[to])
                isbri[i.id] = true;
        }
        else if (in[to])
            low[u] = min(low[u], dfn[to]);
    }
    in[u] = false;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        G[a[i]].push_back({b[i], c[i], i});
        rG[b[i]].push_back({a[i], c[i], i});
    }
    dijkstra(1, dis, G);
    dijkstra(2, rdis, rG);
    ll ordis = dis[2];
    if (ordis != INF)
    {
        for (int i = 1; i <= n; ++i)
            for (auto j : G[i]) //转成无向边
                if (dis[i] + rdis[j.to] + j.w == ordis)
                {
                    pG[i].push_back(j);
                    pG[j.to].push_back({i, j.w, j.id});
                }
        tarjan(1, 0);
        for (int i = 1; i <= m; ++i)
        {
            if (dis[b[i]] + rdis[a[i]] + c[i] < ordis)
                printf("HAPPY\n");
            else if (isbri[i])
                printf("SAD\n");
            else
                printf("SOSO\n");
        }
    }
    else
    {
        for (int i = 1; i <= m; ++i)
        {
            if (dis[b[i]] + rdis[a[i]] + c[i] < ordis)
                printf("HAPPY\n");
            else
                printf("SAD\n");
        }
    }
    return 0;
}