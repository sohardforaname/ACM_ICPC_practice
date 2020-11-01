#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct Tree
{
    int ls[N << 5], rs[N << 5], sum[N << 5];
    int cnt, rt[N];
    void upd(int lst, int &rt, int l, int r, int pos, int val)
    {
        rt = ++cnt;
        sum[rt] = sum[lst] + val;
        ls[rt] = ls[lst];
        rs[rt] = rs[lst];
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(ls[lst], ls[rt], l, mid, pos, val);
        else
            upd(rs[lst], rs[rt], mid + 1, r, pos, val);
    }
    int query(int rt, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return sum[rt];
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid)
            res += query(ls[rt], l, mid, ql, qr);
        if (qr > mid)
            res += query(rs[rt], mid + 1, r, ql, qr);
        return res;
    }
    int bsearch(int rt, int l, int r, int val)
    {
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        if (sum[rs[rt]] >= val)
            return bsearch(rs[rt], mid + 1, r, val);
        else
            return bsearch(ls[rt], l, mid, val - sum[rs[rt]]);
    }
};
Tree tr;
int a[N], b[N], lim[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = i - a[i];
        if (b[i] < 0)
        {
            b[i] = -1;
            lim[i] = -1;
            tr.rt[i] = tr.rt[i - 1];
            continue;
        }
        if (tr.sum[tr.rt[i - 1]] < b[i])
        {
            lim[i] = -1;
            tr.rt[i] = tr.rt[i - 1];
            continue;
        }
        if (!b[i])
            lim[i] = i - 1;
        else
            lim[i] = tr.bsearch(tr.rt[i - 1], 0, n - 1, b[i]);
        tr.upd(tr.rt[i - 1], tr.rt[i], 0, n - 1, lim[i], 1);
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", tr.query(tr.rt[n - y], 0, n - 1, x, n));
    }
    return 0;
}