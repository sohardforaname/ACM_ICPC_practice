#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
#define ls (k << 1)
#define rs ((k << 1) + 1)
int n, m;
struct y_segtree
{
    int maxn[(1 << 11) + 5], tag[(1 << 11) + 5];
    void update(int k, int l, int r, int ql, int qr, int val)
    {
        maxn[k] = max(maxn[k], val);
        if (ql <= l && r <= qr)
        {
            tag[k] = max(tag[k], val);
            return;
        }
        int m = (l + r) >> 1;
        if (ql <= m)
            update(ls, l, m, ql, qr, val);
        if (qr > m)
            update(rs, m + 1, r, ql, qr, val);
    }
    int query(int k, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return maxn[k];
        int m = (l + r) >> 1, ans = tag[k];
        if (ql <= m)
            ans = max(ans, query(ls, l, m, ql, qr));
        if (qr > m)
            ans = max(ans, query(rs, m + 1, r, ql, qr));
        return ans;
    }
};
struct x_segtree
{
    y_segtree maxn[(1 << 11) + 5], tag[(1 << 11) + 5];
    void update(int k, int l, int r, int ql, int qr, int yl, int yr, int val)
    {
        maxn[k].update(1, 1, m, yl, yr, val);
        if (ql <= l && r <= qr)
        {
            tag[k].update(1, 1, m, yl, yr, val);
            return;
        }
        int m = (l + r) >> 1;
        if (ql <= m)
            update(ls, l, m, ql, qr, yl, yr, val);
        if (qr > m)
            update(rs, m + 1, r, ql, qr, yl, yr, val);
    }
    int query(int k, int l, int r, int ql, int qr, int yl, int yr)
    {
        if (ql <= l && r <= qr)
            return maxn[k].query(1, 1, m, yl, yr);
        int res = tag[k].query(1, 1, m, yl, yr);
        int m = (l + r) >> 1;
        if (ql <= m)
            res = max(res, query(ls, l, m, ql, qr, yl, yr));
        if (qr > m)
            res = max(res, query(rs, m + 1, r, ql, qr, yl, yr));
        return res;
    }
};
x_segtree tr;
int main()
{
    int t;
    scanf("%d%d%d", &n, &m, &t);
    int di, si, wi, xi, yi;
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d%d%d%d%d", &di, &si, &wi, &xi, &yi);
        ++xi, ++yi;
        int tmp = tr.query(1, 1, n, xi, xi + di - 1, yi, yi + si - 1);
        tr.update(1, 1, n, xi, xi + di - 1, yi, yi + si - 1, tmp + wi);
    }
    printf("%d\n", tr.query(1, 1, n, 1, n, 1, m));
    return 0;
}