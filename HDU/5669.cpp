#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
struct edge
{
    int v, w;
    edge() {}
    edge(int _v, int _w) : v(_v), w(_w) {}
};
int n, m, k;
vector<edge> G[N << 3];
struct segtree
{
    struct node
    {
        int l, r;
    };
    node tr[N << 3];
    int cnt;
    void buildin(int &rt, int l, int r)
    {
        if (l == r)
        {
            rt = l;
            return;
        }
        rt = ++cnt;
        int m = (l + r) >> 1;
        buildin(tr[rt].l, l, m);
        buildin(tr[rt].r, m + 1, r);
        G[tr[rt].l].push_back({rt, 0});
        G[tr[rt].r].push_back({rt, 0});
    }
    void buildout(int &rt, int l, int r)
    {
        if (l == r)
        {
            rt = l;
            return;
        }
        rt = ++cnt;
        int m = (l + r) >> 1;
        buildout(tr[rt].l, l, m);
        buildout(tr[rt].r, m + 1, r);
        G[rt].push_back({tr[rt].l, 0});
        G[rt].push_back({tr[rt].r, 0});
    }
    void update(int rt, int l, int r, int ql, int qr, int w, int op)
    {
        if (ql > qr)
            return;
        if (ql <= l && r <= qr)
        {
            if (op == 0) //入度树
                G[rt].push_back({cnt, w});
            else if (op == 1)
                G[cnt].push_back({rt, w});
            return;
        }
        int m = (l + r) >> 1;
        if (ql <= m)
            update(tr[rt].l, l, m, ql, qr, w, op);
        if (qr > m)
            update(tr[rt].r, m + 1, r, ql, qr, w, op);
    }
};
segtree tr;
int dis[15][N << 3];
bool vis[15][N << 3];
struct node
{
    int w, v, div;
    node() {}
    node(int _w, int _v, int _div) : w(_w), v(_v), div(_div) {}
    bool operator<(const node &a) const
    {
        return w > a.w;
    }
};
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    dis[0][1] = 0;
    q.push({0, 1, 0});
    while (q.size())
    {
        node cur = q.top();
        q.pop();
        if (vis[cur.div][cur.v])
            continue;
        vis[cur.div][cur.v] = 1;
        for (auto i : G[cur.v])
        {
            if (cur.div < k && dis[cur.div + 1][i.v] > dis[cur.div][cur.v])
            {
                dis[cur.div + 1][i.v] = dis[cur.div][cur.v];
                q.push({dis[cur.div + 1][i.v], i.v, cur.div + 1});
            }
            if (dis[cur.div][i.v] > dis[cur.div][cur.v] + i.w)
            {
                dis[cur.div][i.v] = dis[cur.div][cur.v] + i.w;
                q.push({dis[cur.div][i.v], i.v, cur.div});
            }
        }
    }
}
int inrt, outrt;
int main()
{
    scanf("%d", &n);
    scanf("%d%d%d", &n, &m, &k);
    tr.cnt = n;
    tr.buildin(inrt, 1, n);
    tr.buildout(outrt, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c, d, w;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &w);
        ++tr.cnt;
        tr.update(inrt, 1, n, a, b, w, 0);
        tr.update(outrt, 1, n, c, d, 0, 1);
        ++tr.cnt;
        tr.update(inrt, 1, n, c, d, w, 0);
        tr.update(outrt, 1, n, a, b, 0, 1);
    }
    dijkstra();
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dis[i][n]);
    printf("%d\n", ans);
    return 0;
}
