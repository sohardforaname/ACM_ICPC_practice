#include "../base.h"

const int N = 2e5 + 5;
bool multi = 1;

char s[N], s1[N];
struct tree
{
    int lazy, sum;
    int l, r;
} tr[N << 2];
#define ls (k << 1)
#define rs ((k << 1) + 1)
void pushup(int k)
{
    tr[k].sum = tr[ls].sum + tr[rs].sum;
}
void build(int l, int r, int k)
{
    tr[k].lazy = 2;
    tr[k].l = l, tr[k].r = r;
    if (l == r)
    {
        if (s1[l] - '0')
            tr[k].sum = 1;
        else
            tr[k].sum = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, ls);
    build(m + 1, r, rs);
    pushup(k);
}
void pushdown(int k)
{
    if (tr[k].lazy == 2)
        return;
    tr[ls].lazy = tr[k].lazy;
    tr[rs].lazy = tr[k].lazy;
    tr[ls].sum = (tr[ls].r - tr[ls].l + 1) * tr[k].lazy;
    tr[rs].sum = (tr[rs].r - tr[rs].l + 1) * tr[k].lazy;
    tr[k].lazy = 2;
}
void update(int ql, int qr, int l, int r, int k, int v)
{
    if (ql <= l && r <= qr)
    {
        tr[k].lazy = v;
        tr[k].sum = (r - l + 1) * v;
        return;
    }
    pushdown(k);
    int m = (l + r) >> 1;
    if (ql <= m)
        update(ql, qr, l, m, ls, v);
    if (qr > m)
        update(ql, qr, m + 1, r, rs, v);
    pushup(k);
}
int query(int ql, int qr, int l, int r, int k)
{
    if (ql <= l && r <= qr)
        return tr[k].sum;
    pushdown(k);
    int m = (l + r) >> 1;
    int sum = 0;
    if (ql <= m)
        sum += query(ql, qr, l, m, ls);
    if (qr > m)
        sum += query(ql, qr, m + 1, r, rs);
    return sum;
}
pair<int, int> p[N];
void solve()
{
    int n, q;
    io(n, q);
    io(s + 1);
    io(s1 + 1);
    build(1, n, 1);
    for (int i = 1; i <= q; ++i)
        io(p[i].first, p[i].second);
    for (int i = q; i >= 1; --i)
    {
        int l = p[i].first, r = p[i].second;
        int sum = query(l, r, 1, n, 1);
        int z = r - l + 1 - sum, o = sum;
        if (z < o)
            update(l, r, 1, n, 1, 1);
        else if (z > o)
            update(l, r, 1, n, 1, 0);
        else
            return void(printf("NO\n"));
    }
    for (int i = 1; i <= n; ++i)
        if (s[i] != query(i, i, 1, n, 1) + '0')
            return void(printf("NO\n"));
    printf("YES\n");
}

int main()
{
    int t;
    if (multi)
        io(t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}