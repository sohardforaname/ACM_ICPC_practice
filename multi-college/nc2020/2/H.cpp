#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int inf = 0x7fffffff;
int mp[N];
int b[N], top;
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
    struct node
    {
        int l, r, maxn, minn, gap;
    };
    node tr[N << 1];
    inline void pushup(int k)
    {
        tr[k].maxn = max(tr[ls].maxn, tr[rs].maxn);
        tr[k].minn = min(tr[ls].minn, tr[rs].minn);
        tr[k].gap = min(tr[ls].gap, tr[rs].gap);
        tr[k].gap = min(tr[k].gap, tr[rs].minn - tr[ls].maxn);
    }
    void build(int l, int r, int k)
    {
        tr[k].l = l;
        tr[k].r = r;
        if (l == r)
        {
            tr[k].maxn = 0;
            tr[k].minn = inf;
            tr[k].gap = inf;
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, ls);
        build(m + 1, r, rs);
        pushup(k);
    }
    void update(int k, int pos, int val)
    {
        if (tr[k].l == tr[k].r)
        {
            mp[pos] += val;
            tr[k].gap = inf;
            if (mp[pos] == 0)
            {
                tr[k].maxn = 0;
                tr[k].minn = inf;
            }
            else
            {
                tr[k].maxn = tr[k].minn = b[pos];
                if (mp[pos] >= 2)
                    tr[k].gap = 0;
            }
            return;
        }
        int m = (tr[k].l + tr[k].r) >> 1;
        if (pos <= m)
            update(ls, pos, val);
        else
            update(rs, pos, val);
        pushup(k);
    }
    int querym(int l, int r, int k, int op)
    {
        if (l > r)
            return op ? 0 : inf;
        if (l <= tr[k].l && tr[k].r <= r)
            return op ? tr[k].maxn : tr[k].minn;
        int m = (tr[k].l + tr[k].r) >> 1;
        int ans1 = 0, ans2 = inf, tmp;
        if (l <= m)
        {
            tmp = querym(l, r, ls, op);
            ans1 = max(ans1, tmp);
            ans2 = min(ans2, tmp);
        }
        if (r > m)
        {
            tmp = querym(l, r, rs, op);
            ans1 = max(ans1, tmp);
            ans2 = min(ans2, tmp);
        }
        return op ? ans1 : ans2;
    }
    int queryg(int l, int r, int k)
    {
        if (l > r)
            return inf;
        if (l <= tr[k].l && tr[k].r <= r)
            return tr[k].gap;
        int m = (tr[k].l + tr[k].r) >> 1;
        int ans = inf;
        int f = 0;
        if (l <= m)
            ans = min(ans, queryg(l, r, ls)), ++f;
        if (r > m)
            ans = min(ans, queryg(l, r, rs)), ++f;
        if (f == 2)
            ans = min(ans, tr[rs].minn - tr[ls].maxn);
        return ans;
    }
#undef ls
#undef rs
};
pair<int, int> q[N];
#define x first
#define y second
segtree tr;
bool check(int op, int pos, int val)
{
    if (mp[pos] >= 2)
        return 1;
    else if (mp[pos] == 1)
    {
        int maxn = tr.querym(1, pos - 1, 1, 1);
        if (maxn != 0)
            return 1;
        int ming = tr.queryg(pos, top, 1);
        if (ming < val)
            return 1;
        return 0;
    }
    int maxn = tr.querym(1, pos, 1, 1);
    int minn = tr.querym(pos, top, 1, 0);
    if (maxn != 0 && minn != inf && maxn + val > minn)
        return 1;
    int mpos = lower_bound(b + 1, b + top + 1, maxn) - b;
    if (maxn)
    {
        tr.update(1, mpos, -1);
        int smaxn = tr.querym(1, pos, 1, 1);
        tr.update(1, mpos, 1);
        if (smaxn && smaxn + maxn > val)
            return 1;
    }
    int ming = tr.queryg(pos, top, 1);
    if (ming < val)
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &q[i].x, &q[i].y);
        b[++top] = q[i].y;
    }
    sort(b + 1, b + top + 1);
    top = unique(b + 1, b + top + 1) - b - 1;
    for (int i = 1; i <= n; ++i)
        q[i].y = lower_bound(b + 1, b + top + 1, q[i].y) - b;
    tr.build(1, top, 1);
    for (int i = 1; i <= n; ++i)
    {
        if (q[i].x == 1)
            tr.update(1, q[i].y, 1);
        else if (q[i].x == 2)
            tr.update(1, q[i].y, -1);
        else
            printf("%s", check(q[i].x, q[i].y, b[q[i].y]) ? "Yes\n" : "No\n");
    }
    return 0;
}