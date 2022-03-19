#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
typedef long long ll;
const ll seed = 998244353;

int rt[N];

int l[N], r[N], p[N], sz[N], pos[N];
ll sum[N], val[N], tag[N];

int rand()
{
    return seed * 104831ll % 0x7fffffff;
}

void pushdown(int id)
{
    if (tag[id]) {
        tag[l[id]] += tag[id];
        tag[r[id]] += tag[id];

        val[l[id]] += tag[id];
        val[r[id]] += tag[id];
        tag[id] = 0;
    }
}

void pushup(int id)
{
    sum[id] = sum[l[id]] + sum[r[id]];
    sz[id] = sz[l[id]] + sz[r[id]];
}

int create(int ps, int v)
{
    l[ps] = r[ps] = 0;
    p[ps] = rand();
    sz[ps] = 1;
    pos[ps] = ps;
    sum[ps] = val[ps] = v;
    tag[ps] = 0;
    return ps;
}

void split(int rt, int v, int& x, int& y)
{
    if (!rt) {
        x = y = 0;
        return;
    }
    pushdown(rt);
    if (v >= pos[rt]) {
        x = rt;
        split(r[rt], v, r[rt], y);
    } else {
        y = rt;
        split(l[rt], v, x, l[rt]);
    }
    pushup(rt);
}

int merge(int x, int y)
{
    if (!x || !y) {
        return x + y;
    }

    if (p[x] > p[y]) {
        pushdown(x);
        r[x] = merge(r[x], y);
        pushup(x);
        return x;
    } else {
        pushdown(y);
        l[y] = merge(x, l[y]);
        pushup(y);
        return y;
    }
}

int build(int ql, int qr)
{
    if (ql > qr) {
        return 0;
    }
    int m = (ql + qr) >> 1;
    int root = create(m, 0);
    l[root] = build(ql, m - 1);
    r[root] = build(m + 1, qr);
    return root;
}

char op[10];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    rt[1] = build(1, n);
    int l, r, c, v;
    while (q--) {
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d%d", &l, &r, &c);
            int crt = rt[c];
            int x, y, z;
            split(crt, l - 1, x, y);
            split(y, r, y, z);
        } else if (op[0] == 'A') {

        } else if (op[0] == 'Q') {
        }
    }
    return 0;
}
