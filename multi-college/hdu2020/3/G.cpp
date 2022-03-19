#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
struct edge
{
    int to, w;
    edge() {}
    edge(int _to, int _w) : to(_to), w(_w) {}
    bool operator<(const edge &a) const
    {
        return w > a.w;
    }
};
int head[N * N], nxt[N * N];
edge e[N * N];
int cnt;
void add(int u, int v, int w)
{
    e[cnt] = {v, w};
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
int dis[N];
bool vis[N];
priority_queue<edge> q;
edge pre[N];
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    dis[s] = 0;
    q.push({s, 0});
    while (q.size())
    {
        edge cur = q.top();
        q.pop();
        if (vis[cur.to])
            continue;
        vis[cur.to] = 1;
        for (int i = head[cur.to]; ~i; i = nxt[i])
        {
            int v = e[i].to;
            if (dis[v] > dis[cur.to] + e[i].w)
            {
                dis[v] = dis[cur.to] + e[i].w;
                q.push({v, dis[v]});
                pre[v] = {cur.to, i};
            }
        }
    }
}
void solve()
{
    int n, k;
    int u, v, w;
    scanf("%d%d", &n, &k);
    memset(head, -1, sizeof(head[0]) * (n + 3));
    memset(nxt, -1, sizeof(nxt[0]) * (n + 3) * (n + 3));
    cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
    while (k--)
    {
        dijkstra(1);
        int minn = 0x3f3f3f3f, mine, minv;
        int tmpv = n;
        while (tmpv != 1)
        {
            if (e[pre[tmpv].w].w < minn)
            {
                minn = e[pre[tmpv].w].w;
                mine = pre[tmpv].w;
                minv = pre[tmpv].to;
            }
            tmpv = pre[tmpv].to;
        }
        if (head[minv] == mine)
            head[minv] = nxt[mine];
        for (int j = head[minv]; ~j; j = nxt[j])
            if (nxt[j] == mine)
            {
                nxt[j] = nxt[mine];
                break;
            }
        minv = e[mine].to;
        mine ^= 1;
        if (head[minv] == mine)
            head[minv] = nxt[mine];
        for (int j = head[minv]; ~j; j = nxt[j])
            if (nxt[j] == mine)
            {
                nxt[j] = nxt[mine];
                break;
            }
    }
    dijkstra(1);
    printf("%d\n", dis[n]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}