#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
struct Segtree
{
    int ls[N << 5], rs[N << 5];
    int sum[N << 5], rt[N << 5];
    int cnt;
    void update(int &rt, int lst, int l, int r, int val)
    {
        rt = ++cnt;
        sum[rt] = sum[lst] + 1;
        ls[rt] = ls[lst];
        rs[rt] = rs[lst];
        if (l == r)
            return;
        int m = (l + r) >> 1;
        if (val <= m)
            update(ls[rt], ls[lst], l, m, val);
        else
            update(rs[rt], rs[lst], m + 1, r, val);
    }
    int query(int ql, int qr, int l, int r, int k)
    {
        if (sum[qr] - sum[ql] <= k)
            return 0;
        if (l == r)
            return l;
        int m = (l + r) >> 1;
        int x = sum[ls[qr]] - sum[ls[ql]];
        if (x > k)
            return query(ls[ql], ls[qr], l, m, k);
        else
            return query(rs[ql], rs[qr], m + 1, r, k);
    }
};
Segtree tr;
int c[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i)
        tr.update(tr.rt[i], tr.rt[i - 1], 1, 5e4, c[i]);
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", tr.query(tr.rt[a - 1], tr.rt[b], 1, 5e4, (b - a + 1) / 2));
    }
    return 0;
}