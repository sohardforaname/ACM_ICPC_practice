#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct segtree
{
    struct node
    {
        int l, r, sum;
    };
    int cnt, rt[N];
    node tr[N << 6];
    void update(int &rt, int lst, int l, int r, int val)
    {
        rt = ++cnt;
        tr[rt] = tr[lst];
        ++tr[rt].sum;
        if (l == r)
            return;
        int m = (l + r) >> 1;
        if (val <= m)
            update(tr[rt].l, tr[lst].l, l, m, val);
        else
            update(tr[rt].r, tr[lst].r, m + 1, r, val);
    }
    int query(int ql, int qr, int l, int r, int k)
    {
        if (tr[qr].sum - tr[ql].sum <= k)
            return -1;
        if (l == r)
            return l;
        int m = (l + r) >> 1;
        int ans = -1;
        if (tr[tr[qr].l].sum - tr[tr[ql].l].sum > k)
            ans = query(tr[ql].l, tr[qr].l, l, m, k);
        if (ans == -1)
            ans = query(tr[ql].r, tr[qr].r, m + 1, r, k);
        return ans;
    }
};
segtree tr;
int c[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i)
        tr.update(tr.rt[i], tr.rt[i - 1], 1, n, c[i]);
    for (int i = 1; i <= m; ++i)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", tr.query(tr.rt[l - 1], tr.rt[r], 1, n, (r - l + 1) / k));
    }
    return 0;
}