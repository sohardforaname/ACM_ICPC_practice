#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct node
{
    ll a, b;
    int id;
    bool operator<(const node x) const
    {
        if (a == x.a)
        {
            return id > x.id;
        }
        return a > x.a;
    }
};
node v[N], sum[N];
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
    struct node
    {
        int l, r, lazy;
        ll minn;
    };
    node tr[N << 2];
    void pushdown(int k)
    {
        tr[ls].lazy += tr[k].lazy;
        tr[rs].lazy += tr[k].lazy;
        tr[ls].minn += tr[k].lazy;
        tr[rs].minn += tr[k].lazy;
        tr[k].lazy = 0;
    }
    void pushup(int k)
    {
        tr[k].minn = min(tr[ls].minn, tr[rs].minn);
    }
    void build(int l, int r, int k)
    {
        tr[k].l = l, tr[k].r = r;
        if (l == r)
        {
            tr[k].minn = v[l].b;
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, ls);
        build(m + 1, r, rs);
        pushup(k);
    }
    void update(int l, int r, int k, ll val)
    {
        if (l <= tr[k].l && tr[k].r <= r)
        {
            tr[k].lazy += val;
            tr[k].minn += val;
            return;
        }
        pushdown(k);
        int m = (tr[k].l + tr[k].r) >> 1;
        if (l <= m)
            update(l, r, ls, val);
        if (r > m)
            update(l, r, rs, val);
        pushup(k);
    }
    ll query_min(int l, int r, int k)
    {
        if (l <= tr[k].l && tr[k].r <= r)
            return tr[k].minn;
        pushdown(k);
        int m = (tr[k].l + tr[k].r) >> 1;
        ll ans = 1e9 + 7;
        if (l <= m)
            ans = min(ans, query_min(l, r, ls));
        if (r > m)
            ans = min(ans, query_min(l, r, rs));
        return ans;
    }
    int query_zero(int l, int r, int k)
    {
        if (l <= tr[k].l && tr[k].r <= r)
        {
            if (tr[k].l == tr[k].r)
                return tr[k].minn == 0 ? tr[k].l : 1e9 + 7;
            if (tr[ls].minn <= 0)
                return query_zero(l, r, ls);
            if (tr[rs].minn <= 0)
                return query_zero(l, r, rs);
            return 1e9 + 7;
        }
        pushdown(k);
        int m = (tr[k].l + tr[k].r) >> 1;
        int ans = 1e9 + 7;
        if (l <= m)
            ans = min(ans, query_zero(l, r, ls));
        if (r > m)
            ans = min(ans, query_zero(l, r, rs));
        return ans;
    }
};