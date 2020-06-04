#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct edge
{
    int u, v, w;
    edge() {}
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge &a) const
    {
        return w < a.w;
    }
};
edge e[N * 5];
struct Query
{
    int v, x, k, i;
    bool operator<(const Query &a) const
    {
        return x < a.x;
    }
};
Query que[N * 5];
struct node
{
    int l, r, sum;
};
int cnt, rt[N];
node tr[N * 18];
void update(int &rt, int l, int r, int pos, int val)
{
    if (!rt)
        rt = ++cnt;
    tr[rt].sum += val;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (pos <= m)
        update(tr[rt].l, l, m, pos, val);
    else if (pos > m)
        update(tr[rt].r, m + 1, r, pos, val);
}
int query(int rt, int l, int r, int k)
{
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    if (tr[tr[rt].r].sum >= k)
        return query(tr[rt].r, m + 1, r, k);
    return query(tr[rt].l, l, m, k - tr[tr[rt].r].sum);
}
void merge(int &lt, int rt, int l, int r)
{
    if (!lt || !rt)
    {
        lt += rt;
        return;
    }
    tr[lt].sum += tr[rt].sum;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    merge(tr[lt].l, tr[rt].l, l, m);
    merge(tr[lt].r, tr[rt].r, m + 1, r);
}
int fa[N], val[N];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int n, m, q;
void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx ^ fy)
    {
        fa[fx] = fy;
        val[fy] += val[fx];
        merge(rt[fy], rt[fx], 1, n);
    }
}
int h[N], b[N], ans[N * 5];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]), h[i] = b[i];
    sort(b + 1, b + n + 1);
    int top = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; ++i)
        h[i] = lower_bound(b + 1, b + top + 1, h[i]) - b;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= q; ++i)
        scanf("%d%d%d", &que[i].v, &que[i].x, &que[i].k), que[i].i = i;
    sort(que + 1, que + q + 1);
    for (int i = 1; i <= n; ++i)
        fa[i] = i, val[i] = 1, update(rt[i], 1, n, h[i], 1);
    int cur = 1;
    for (int i = 1; i <= q; ++i)
    {
        while (cur <= m && e[cur].w <= que[i].x)
        {
            join(e[cur].u, e[cur].v);
            ++cur;
        }
        int u = find(que[i].v);
        if (val[u] < que[i].k)
            ans[que[i].i] = 0;
        else
            ans[que[i].i] = query(rt[u], 1, n, que[i].k);
    }
    b[0] = -1;
    for (int i = 1; i <= q; ++i)
        printf("%d\n", b[ans[i]]);
    return 0;
}