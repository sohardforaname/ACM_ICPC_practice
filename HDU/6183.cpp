#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 1000005;
const int M = 0x3f3f3f3f;

struct segtree
{
    struct node
    {
        int l, r, ls, rs, sum, minn;
        /*node()
        {
            l=r=ls=rs=sum=0;
            minn=M;
        }*/
    };
    node tr[MAXN * 3];
    int rt[51];
    int tot = 0;
    inline void init()
    {
        memset(rt, 0, sizeof(rt));
        for (int i = 0; i < MAXN * 3; ++i)
            tr[i].l = tr[i].r = tr[i].ls = tr[i].rs = tr[i].sum = 0, tr[i].minn = M;
        tot = 0;
    }
    inline void update(int &rt, int l, int r, int pos, int val)
    {
        if (!rt)
            rt = ++tot;
        ++tr[rt].sum;
        tr[rt].l = l;
        tr[rt].r = r;
        tr[rt].minn = min(tr[rt].minn, val);
        if (l == r)
            return;
        int m = (l + r) >> 1;
        if (pos <= m)
            update(tr[rt].ls, l, m, pos, val);
        else
            update(tr[rt].rs, m + 1, r, pos, val);
        tr[rt].sum = tr[tr[rt].ls].sum + tr[tr[rt].rs].sum;
    }
    inline bool query(int l, int r, int rt, int lim)
    {
        if (!rt)
            return false;
        if (l <= tr[rt].l && tr[rt].r <= r)
        {
            if (tr[rt].minn <= lim && tr[rt].sum)
                return true;
            else
                return false;
        }
        int ans = 0;
        int m = (tr[rt].l + tr[rt].r) >> 1;
        if (l <= m && !ans)
            ans += query(l, r, tr[rt].ls, lim);
        if (r > m && !ans)
            ans += query(l, r, tr[rt].rs, lim);
        return ans;
    }
};

segtree tr;
int main()
{
    int a, b, c, d;
    while (scanf("%d", &a) && a != 3)
    {
        if (a == 0)
            tr.init();
        else if (a == 1)
        {
            scanf("%d%d%d", &b, &c, &d);
            tr.update(tr.rt[d], 1, 1000000, c, b);
        }
        else if (a == 2)
        {
            int ans = 0;
            scanf("%d%d%d", &b, &c, &d);
            for (int i = 0; i <= 50; ++i)
                ans += tr.query(c, d, tr.rt[i], b);
            printf("%d\n", ans);
        }
    }
    return 0;
}
