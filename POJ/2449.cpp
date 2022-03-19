#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 8e3 + 5;
const int M = 1e5 + 5;
struct edge
{
    int u, v, w, f, nxt;
    bool vis, flag;
};
edge e[M];
struct edge_rev
{
    int t, w, nxt;
};
edge_rev e_rev[M];
bool vis[N];
int G[N], G_rev[N];
int dis[N], nxt[N], rt[N];
int sta[N];
int cnt, cnt_rev;
void adde(int u, int v, int w)
{
    ++cnt;
    e[cnt].u = u, e[cnt].v = v, e[cnt].w = w;
    e[cnt].nxt = G[u], G[u] = cnt;
    e[cnt].vis = 0;
}
void adde_rev(int u, int v, int w)
{
    ++cnt_rev;
    e_rev[cnt_rev].t = v;
    e_rev[cnt_rev].w = w;
    e_rev[cnt_rev].nxt = G_rev[u], G_rev[u] = cnt_rev;
}

struct node
{
    int l, r, dis;
    int c, y;
};
node tr[N * 100];
int tot;
int newnode(int c, int y)
{
    ++tot;
    tr[tot].l = tr[tot].r = 0;
    tr[tot].dis = 0;
    tr[tot].c = c;
    tr[tot].y = y;
    return tot;
}
int merge(int x, int y)
{
    if (!x || !y)
        return x + y;
    if (tr[x].c > tr[y].c)
        swap(x, y);
    int ret = ++tot;
    tr[ret] = tr[x];
    int k = merge(tr[ret].r, y);
    if (tr[tr[ret].l].dis <= tr[k].dis)
        swap(tr[ret].l, k);
    tr[ret].r = k;
    tr[ret].dis = tr[tr[ret].l].dis + 1;
    return ret;
}

struct heapnode
{
    int x, d;
    bool operator<(const heapnode &a) const
    {
        return d > a.d;
    }
};
priority_queue<heapnode> q;
struct graphnode
{
    int u, x, d;
    bool operator<(const graphnode &a) const
    {
        return d > a.d;
    }
};
priority_queue<graphnode> Q;
int st, ed;
void dijkstra()
{
    dis[ed] = 0;
    heapnode tmp;
    tmp.x = ed, tmp.d = 0;
    q.push(tmp);
    while (q.size())
    {
        heapnode cur = q.top();
        q.pop();
        if (dis[cur.x] < cur.d)
            continue;
        for (int v = G_rev[cur.x]; v; v = e_rev[v].nxt)
        {
            int y = e_rev[v].t;
            vis[y] = 1;
            if (dis[y] > cur.d + e_rev[v].w)
            {
                dis[y] = cur.d + e_rev[v].w;
                tmp.x = y, tmp.d = dis[y];
                q.push(tmp);
            }
        }
    }
}

int k;
void solve(int u)
{
    if (u == ed)
    {
        for (int v = G[u]; v; v = e[v].nxt)
        {
            int y = e[v].v;
            if (!e[v].flag)
                continue;
            if (!e[v].vis)
                rt[u] = merge(rt[u], newnode(e[v].f, e[v].v));
        }
        return;
    }
    for (int v = G[u]; v; v = e[v].nxt)
    {
        int y = e[v].v;
        if (!e[v].flag)
            continue;
        if (!e[v].vis)
            rt[u] = merge(rt[u], newnode(e[v].f, e[v].v));
        else
            rt[u] = merge(rt[u], rt[y]);
    }
}
int n, m;
int main()
{
    int u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        adde(u, v, w);
        e[cnt].flag = 1;
        adde_rev(v, u, w);
    }
    scanf("%d%d%d", &st, &ed, &k);
    if (st == ed)
        ++k;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dijkstra();
    if (k == 1)
    {
        if (vis[st])
            printf("%d\n", dis[st]);
        else
            printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        e[i].f = e[i].w - dis[e[i].u] + dis[e[i].v];
        if (dis[e[i].v] == 0x3f3f3f3f)
            e[i].flag = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == ed)
            continue;
        for (int v = G[i]; v; v = e[v].nxt)
        {
            int y = e[v].v;
            if (!e[v].flag)
                continue;
            if (dis[i] == dis[y] + e[v].w)
            {
                e[v].vis = 1;
                nxt[i] = y;
                break;
            }
        }
    }
    memset(rt, 0, sizeof(rt));
    tot = 0;
    int top;
    for (int i = 1; i <= n; ++i)
        if (!rt[i])
        {
            if (dis[i] == 0x3f3f3f3f)
                continue;
            sta[top = 1] = i;
            while (1)
            {
                u = sta[top];
                if (u == ed)
                    break;
                if (!rt[nxt[u]])
                    sta[++top] = nxt[u];
                else
                    break;
            }
            while (top)
                solve(sta[top--]);
        }
    k -= 2;
    graphnode ss;
    ss.u = st, ss.d = tr[rt[st]].c, ss.x = rt[st];
    Q.push(ss);
    while (k--)
    {
        graphnode tmp = Q.top();
        Q.pop();
        if (!tmp.u)
        {
            printf("-1\n");
            return 0;
        }
        if (tr[tmp.x].l)
        {
            graphnode tmp1;
            tmp1.u = tmp.u;
            tmp1.d = -tr[tmp.x].c;
            tmp1.x = merge(tr[tmp.x].l, tr[tmp.x].r);
            tmp1.d += tr[tmp1.x].c + tmp.d;
            Q.push(tmp1);
        }
        graphnode tmp2;
        tmp2.u = tr[tmp.x].y;
        tmp2.d = tmp.d + tr[rt[tmp2.u]].c;
        tmp2.x = rt[tmp2.u];
        Q.push(tmp2);
    }
    graphnode ans = Q.top();
    if (!ans.u)
    {
        printf("-1\n");
        return 0;
    }
    if (vis[st])
        printf("%d\n", dis[st] + ans.d);
    else
        printf("-1\n");
    return 0;
}