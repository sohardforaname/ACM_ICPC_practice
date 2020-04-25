#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct que
{
    int id;
    ll x, y;
};
que q[N];
struct tar
{
    int l, r;
};
tar t[N];
int ind[N];
ll b[N << 1];
int top;
bool check(int x, int y, int ind)
{
    return (q[ind].x - x) * (q[ind].x - x) + (q[ind].y - y) * (q[ind].y - y) < q[ind].y * q[ind].y;
}
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
    set<int> tr[N << 3];
    void update(int l, int r, int L, int R, int k, int val, int op)
    {
        if (L <= l && R >= r)
        {
            if (op == 1)
                tr[k].insert(val);
            else
                tr[k].erase(val);
            return;
        }
        int m = (l + r) >> 1;
        if (L <= m)
            update(l, m, L, R, ls, val, op);
        if (R > m)
            update(m + 1, r, L, R, rs, val, op);
    }
    int query(int l, int r, int k, int id, ll x, ll y)
    {
        if (l <= id && r >= id)
            for (auto i : tr[k])
                if (check(x, y, i))
                    return i;
        if (l == r)
            return -1;
        int m = (l + r) >> 1;
        if (id <= m)
            return query(l, m, ls, id, x, y);
        else
            return query(m + 1, r, rs, id, x, y);
    }
};
segtree tr;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%lld%lld", &q[i].id, &q[i].x, &q[i].y);
        if (q[i].id == 1)
            b[++top] = q[i].x - q[i].y, b[++top] = q[i].x + q[i].y;
        else if (q[i].id == 2)
            b[++top] = q[i].x;
    }
    sort(b + 1, b + top + 1);
    top = unique(b + 1, b + top + 1) - (b + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (q[i].id == 1)
        {
            t[i].l = lower_bound(b + 1, b + top + 1, q[i].x - q[i].y) - b;
            t[i].r = lower_bound(b + 1, b + top + 1, q[i].x + q[i].y) - b;
        }
        else
            ind[i] = lower_bound(b + 1, b + top + 1, q[i].x) - b;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (q[i].id == 1)
            tr.update(1, top, t[i].l, t[i].r, 1, i, 1);
        else
        {
            int pos = tr.query(1, top, 1, ind[i], q[i].x, q[i].y);
            if (pos == -1)
                printf("-1\n");
            else
            {
                printf("%d\n", pos);
                tr.update(1, top, t[pos].l, t[pos].r, 1, pos, -1);
            }
        }
    }
    return 0;
}
/*
8
1 0 12
2 -11 22
1 24 10
1 12 3
2 12 12
2 16 14
1 28 15
2 3 6
*/