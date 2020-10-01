#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
typedef long long ll;
int head[N << 1], nxt[N << 1], to[N << 1], l[N << 1];
int tot, n, m;
bool vis[N];
ll dis[N];

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

struct edge
{
    int u, v, l, a;
    bool operator<(const edge &a) const
    {
        return this->a > a.a;
    }
};
edge e[N];
void add(int u, int v, int ql)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    l[tot] = ql;
}
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (q.size())
    {
        pair<ll, int> cur = q.top();
        q.pop();
        if (vis[cur.second])
            continue;
        vis[cur.second] = 1;
        for (int i = head[cur.second]; i; i = nxt[i])
            if (dis[to[i]] > dis[cur.second] + l[i])
            {
                dis[to[i]] = dis[cur.second] + l[i];
                q.push({dis[to[i]], to[i]});
            }
    }
}
int ls[N], rs[N], tcnt;
ll minn[N];
ll dfs(int u)
{
    minn[u] = 0x3f3f3f3f;
    if (!ls[u] || !rs[u])
        return minn[u] = dis[u];
    minn[u] = min(minn[u], dfs(ls[u]));
    minn[u] = min(minn[u], dfs(rs[u]));
    return minn[u];
}
int fa[N << 1], f[N << 1][20];
int g[N << 1][20];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void get_lca(int n)
{
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j <= n; ++j)
        {
            f[j][i] = f[f[j][i - 1]][i - 1];
            g[j][i] = min(g[j][i - 1], g[f[j][i - 1]][i - 1]);
        }
    dfs(tcnt);
}
inline void kruskal()
{
    tcnt = n;
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; ++i)
    {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (fu != fv)
        {
            ls[++tcnt] = fu, rs[tcnt] = fv;
            fa[fu] = fa[fv] = f[fu][0] = f[fv][0] = tcnt;
            g[fu][0] = g[fv][0] = e[i].a;
        }
    }
    get_lca(tcnt);
}
inline int query(int x, int val)
{
    for (int i = 19; ~i; --i)
        if (g[x][i] > val && g[x][i] <= 0x3f3f3f3f)
            x = f[x][i];
    return x;
}
int main()
{
    //freopen("D:\\exe\\return5.in", "r", stdin);
    //freopen("D:\\exe\\return5.out", "w", stdout);
    int T;
    T = read();
    //scanf("%d", &T);
    while (T--)
    {
        memset(g, 0x3f, sizeof(g));
        memset(f, 0, sizeof(f));
        memset(head, 0, sizeof(head));
        memset(ls, 0, sizeof(ls));
        memset(rs, 0, sizeof(rs));
        for (int i = 1; i < N; ++i)
            fa[i] = i;
        tot = 0;

        n = read(), m = read();
        //scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i)
        {
            //scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].l, &e[i].a);
            e[i] = {read(), read(), read(), read()};
            add(e[i].u, e[i].v, e[i].l);
            add(e[i].v, e[i].u, e[i].l);
        }
        dijkstra();
        ll lst = 0;
        kruskal();
        int q = read(), k = read(), s = read();
        //scanf("%d%d%d", &q, &k, &s);
        for (int i = 1; i <= q; ++i)
        {
            int v = read(), p = read();
            //scanf("%d%d", &v, &p);
            v = (v + k * lst - 1) % n + 1;
            p = (p + k * lst) % (s + 1);
            lst = minn[query(v, p)];
            printf("%lld\n", lst);
        }
    }
    return 0;
}