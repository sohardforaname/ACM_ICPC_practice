#include "../base.h"

bool multi = 0;
const int N = 2e5 + 5;

double a[N];
double sinsum[N << 2], cossum[N << 2], lazy[N << 2];

#define ls (k << 1)
#define rs (k << 1 | 1)
void pushup(int k)
{
    sinsum[k] = sinsum[ls] + sinsum[rs];
    cossum[k] = cossum[ls] + cossum[rs];
}
void pushdown(int k)
{
    if (!lazy[k])
        return;
    lazy[ls] += lazy[k];
    lazy[rs] += lazy[k];
    double sb = sin(lazy[k]), cb = cos(lazy[k]);
    double ss = sinsum[ls], cs = cossum[ls];
    sinsum[ls] = ss * cb + cs * sb;
    cossum[ls] = cs * cb - ss * sb;
    ss = sinsum[rs], cs = cossum[rs];
    sinsum[rs] = ss * cb + cs * sb;
    cossum[rs] = cs * cb - ss * sb;
    lazy[k] = 0;
}

void build(int l, int r, int k)
{
    if (l == r) {
        sinsum[k] = sin(a[l]);
        cossum[k] = cos(a[l]);
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, ls);
    build(m + 1, r, rs);
    pushup(k);
}
void update(int ql, int qr, int l, int r, int k, int v)
{
    if (ql <= l && r <= qr) {
        lazy[k] += v;
        double sb = sin(v), cb = cos(v);
        double ss = sinsum[k], cs = cossum[k];
        sinsum[k] = ss * cb + cs * sb;
        cossum[k] = cs * cb - ss * sb;
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
double query(int ql, int qr, int l, int r, int k)
{
    if (ql <= l && r <= qr)
        return sinsum[k];
    pushdown(k);
    int m = (l + r) >> 1;
    double res = 0;
    if (ql <= m)
        res += query(ql, qr, l, m, ls);
    if (qr > m)
        res += query(ql, qr, m + 1, r, rs);
    return res;
}

void solve()
{
    wio.w = 1;
    int n, m;
    io(n);
    io(io.make(a, 1, n + 1));
    build(1, n, 1);
    io(m);
    for (int i = 1; i <= m; ++i) {
        int op, l, r;
        io(op, l, r);
        if (op == 1) {
            int v;
            io(v);
            update(l, r, 1, n, 1, v);
        } else {
            io(query(l, r, 1, n, 1), '\n');
        }
    }
    return;
}

MAIN_FUNC