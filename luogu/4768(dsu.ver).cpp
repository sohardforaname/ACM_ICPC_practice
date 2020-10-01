#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 4e5 + 5;
typedef long long ll;
const int maxbuf = 1 << 20;
char buf[1 << 20], *fh = nullptr, *ft = nullptr;
inline char gc()
{
    if (fh == ft)
    {
        int l = fread(buf, 1, maxbuf, stdin);
        ft = (fh = buf) + l;
    }
    return *fh++;
}

inline int read()
{
    int x = 0;
    char c = gc();
    for (; c < '0' || c > '9'; c = gc())
        ;
    for (; c >= '0' && c <= '9'; c = gc())
        x = (x << 3) + (x << 1) + c - '0';
    return x;
}
inline void _write(long long x)
{
    if (x > 9)
        _write(x / 10);
    putchar(x % 10 + '0');
}
inline void write(long long x)
{
    _write(x);
    putchar('\n');
}
int to[M << 1], head[M << 1], nxt[M << 1], ae[M << 1], le[M << 1], tot;
int n, m, root[M];
ll dis[N];

struct edge
{
    int u, v, l, a;
    bool operator<(const edge &a) const
    {
        return this->a < a.a;
    }
};
edge e[M << 1];
bool vis[N];
void add(int u, int v, int ql, int qa)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    le[tot] = ql;
    ae[tot] = qa;
}
void dijkstra()
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push({0ll, 1});
    dis[1] = 0;
    while (q.size())
    {
        pair<ll, int> p = q.top();
        q.pop();
        if (vis[p.second])
            continue;
        vis[p.second] = 1;
        for (int i = head[p.second]; i; i = nxt[i])
            if (dis[to[i]] > dis[p.second] + le[i])
            {
                dis[to[i]] = dis[p.second] + le[i];
                q.push({dis[to[i]], to[i]});
            }
    }
}
int ls[M * 40], rs[M * 40], fa[M * 40], dep[M * 40];
ll minn[M * 40];
int cnt;
#define mid ((l + r) >> 1)
void build(int &rt, int l, int r)
{
    rt = ++cnt;
    if (l == r)
    {
        fa[rt] = l;
        minn[rt] = dis[l];
        return;
    }
    build(ls[rt], l, mid);
    build(rs[rt], mid + 1, r);
}
int query(int rt, int l, int r, int pos)
{
    if (l == r)
        return rt;
    if (pos <= mid)
        return query(ls[rt], l, mid, pos);
    else
        return query(rs[rt], mid + 1, r, pos);
}
void upd(int &rt, int lst, int l, int r, int pos, int f)
{
    rt = ++cnt;
    ls[rt] = ls[lst];
    rs[rt] = rs[lst];
    if (l == r)
    {
        dep[rt] = dep[lst];
        fa[rt] = f;
        minn[rt] = minn[lst];
        return;
    }
    if (pos <= mid)
        upd(ls[rt], ls[lst], l, mid, pos, f);
    else
        upd(rs[rt], rs[lst], mid + 1, r, pos, f);
}
void updmin(int &rt, int lst, int l, int r, int pos, ll res)
{
    rt = ++cnt;
    ls[rt] = ls[lst];
    rs[rt] = rs[lst];
    if (l == r)
    {
        dep[rt] = dep[lst];
        fa[rt] = fa[lst];
        minn[rt] = res;
        return;
    }
    if (pos <= mid)
        updmin(ls[rt], ls[lst], l, mid, pos, res);
    else
        updmin(rs[rt], rs[lst], mid + 1, r, pos, res);
}
void upddep(int rt, int l, int r, int pos)
{
    if (l == r)
    {
        ++dep[rt];
        return;
    }
    if (pos <= mid)
        upddep(ls[rt], l, mid, pos);
    else
        upddep(rs[rt], mid + 1, r, pos);
}
int find(int rt, int x)
{
    int cur = query(rt, 1, n, x);
    while (fa[cur] != x)
    {
        x = fa[cur];
        cur = query(rt, 1, n, x);
    }
    return cur;
}
void join(int &rt, int cur)
{
    int u = find(rt, e[cur].u);
    int v = find(rt, e[cur].v);
    if (fa[u] != fa[v])
    {
        if (dep[u] > dep[v])
            swap(u, v);
        upd(rt, rt, 1, n, fa[u], fa[v]);
        if (minn[u] < minn[v])
            updmin(rt, rt, 1, n, fa[v], minn[u]);
        if (dep[u] == dep[v])
            upddep(rt, 1, n, fa[v]);
    }
}
int b[M << 1];
int main()
{
    //freopen("d:\\exe\\return5.in", "r", stdin);
    //freopen("d:\\exe\\return5.out", "w", stdout);
    int t = read();
    while (t--)
    {
        n = read(), m = read();
        memset(head, 0, sizeof(head[0]) * (n + 1));
        cnt = tot = 0;
        ll lst = 0;
        for (int i = 1; i <= m; ++i)
        {
            e[i] = {read(), read(), read(), read()};
            add(e[i].u, e[i].v, e[i].l, e[i].a);
            add(e[i].v, e[i].u, e[i].l, e[i].a);
            b[i] = e[i].a;
        }
        dijkstra();
        sort(b + 1, b + m + 1);
        sort(e + 1, e + m + 1);
        int num = unique(b + 1, b + m + 1) - b - 1;
        build(root[num + 1], 1, n);
        int cur = m;
        for (int i = num; i; --i)
        {
            root[i] = root[i + 1];
            while (b[i] == e[cur].a)
            {
                join(root[i], cur);
                --cur;
            }
        }
        int q = read(), k = read(), s = read();
        while (q--)
        {
            int v = read(), p = read();
            v = (v + k * lst - 1) % n + 1;
            p = (p + k * lst) % (s + 1ll);
            int pos = upper_bound(b + 1, b + num + 1, p) - b;
            lst = minn[find(root[pos], v)];
            printf("%lld\n", lst);
        }
    }
    return 0;
}