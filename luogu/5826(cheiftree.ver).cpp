#include "../base.h"

bool multi = 0;
const int N = 1e5 + 5;
int a[N], b[N];

struct node
{
    int l, r, v;
};
node tr[N * 20];
int cnt, rt[N];
void update(int &rt, int lst, int l, int r, int pos, int v)
{
    rt = ++cnt;
    tr[rt] = tr[lst];
    if (l == r)
    {
        tr[rt].v = v;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        update(tr[rt].l, tr[lst].l, l, m, pos, v);
    else
        update(tr[rt].r, tr[lst].r, m + 1, r, pos, v);
}

int query(int rt, int l, int r, int pos)
{
    if (l == r)
        return tr[rt].v;
    int m = (l + r) >> 1;
    if (pos <= m)
        return query(tr[rt].l, l, m, pos);
    else
        return query(tr[rt].r, m + 1, r, pos);
}

void solve()
{
    int ty, n, q, m;
    io(ty, n, q, m);
    for (int i = 1; i <= n; ++i)
        io(a[i]);
    for (int i = n; i; --i)
        update(rt[i], rt[i + 1], 1, m, a[i], i);
    for (int i = 1, l; i <= q; ++i)
    {
        io(l);
        for (int j = 1; j <= l; ++j)
            io(b[j]);
        bool f = 1;
        for (int j = 1, pos = 1; j <= l; ++j)
        {
            pos = query(rt[pos], 1, m, b[j]);
            if (!pos)
            {
                f = 0;
                break;
            }
            ++pos;
        }
        if (f)
            io("Yes", '\n');
        else
            io("No", '\n');
    }
}

MAIN_FUNC