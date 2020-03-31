#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct chieftree
{
    struct node
    {
        int l, r, sum;
    };
    node tr[MAXN * 20];
    int rt[MAXN];
    int cnt;
    void init()
    {
        cnt = 0;
    }
    void build(int &rt, int l, int r)
    {
        rt = ++cnt;
        tr[rt].sum = 0;
        if (l == r)
            return;
        int m = (l + r) / 2;
        build(tr[rt].l, l, m);
        build(tr[rt].r, m + 1, r);
    }
    void update(int &rt, int l, int r, int val)
    {
        tr[++cnt] = tr[rt];
        rt = cnt;
        ++tr[rt].sum;
        if (l == r)
            return;
        int m = (l + r) / 2;
        if (val <= m)
            update(tr[rt].l, l, m, val);
        else
            update(tr[rt].r, m + 1, r, val);
    }
    int query(int rl, int rr, int l, int r, int val)
    {
        int d = tr[tr[rr].r].sum - tr[tr[rl].r].sum;
        if (l == r)
            return l;
        int m = (l + r) / 2;
        if (val <= d)
            return query(tr[rl].r, tr[rr].r, m + 1, r, val);
        else
            return query(tr[rl].l, tr[rr].l, l, m, val - d);
    }
};
chieftree tr;
void print()
{
    for (int i = 1; i <= tr.cnt; ++i)
        cout << tr.tr[i].l << " " << tr.tr[i].r << " " << tr.tr[i].sum << endl;
}
long long a[MAXN], b[MAXN];
long long ans(int l, int r, int n)
{
    if (r - l + 1 < 3)
        return -1;
    int pa = tr.query(tr.rt[l - 1], tr.rt[r], 1, n, 1), pb = tr.query(tr.rt[l - 1], tr.rt[r], 1, n, 2), pc, k = 2;
    do
    {
        pc = tr.query(tr.rt[l - 1], tr.rt[r], 1, n, ++k);
        //cout<<b[pa]<<" "<<b[pb]<<" "<<b[pc]<<endl;
        if (b[pa] < b[pb] + b[pc])
            return b[pa] + b[pb] + b[pc];
        pa = pb;
        pb = pc;
    } while (k < r - l + 1);
    return -1;
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int nnew = unique(b + 1, b + 1 + n) - b - 1;
        tr.init();
        tr.build(tr.rt[0], 1, nnew);
        for (int i = 1; i <= n; ++i)
        {
            tr.rt[i] = tr.rt[i - 1];
            int pos = lower_bound(b + 1, b + 1 + nnew, a[i]) - b;
            //cout<<pos<<endl;
            tr.update(tr.rt[i], 1, nnew, pos);
        }
        //print();
        int aa, bb;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &aa, &bb);
            printf("%lld\n", ans(aa, bb, nnew));
        }
    }
    return 0;
}
