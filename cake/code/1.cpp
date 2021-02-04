#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, M = 1e6 + 5;
ll sum[N << 2];
int a[N];
#define ls (k << 1)
#define rs ((k << 1) + 1)
void build(int l, int r, int k)
{
    if (l == r)
        return void(sum[k] = a[l]);
    int m = (l + r) >> 1;
    build(l, m, ls);
    build(m + 1, r, rs);
    sum[k] = sum[ls] + sum[rs];
}
void update(int l, int r, int k, int pos, int v)
{
    if (l == r)
        return void(sum[k] += v);
    int m = (l + r) >> 1;
    if (pos <= m)
        update(l, m, ls, pos, v);
    else
        update(m + 1, r, rs, pos, v);
    sum[k] = sum[ls] + sum[rs];
}
ll query(int l, int r, int k, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return sum[k];
    ll ans = 0;
    int m = (l + r) >> 1;
    if (ql <= m)
        ans += query(l, m, ls, ql, qr);
    if (qr > m)
        ans += query(m + 1, r, rs, ql, qr);
    return ans;
}
set<int> s[M];
int n, m, tmp[N];
void update(int l, int r, int v)
{
    int top = 0;
    for (int i = v; i <= 1e6; i += v)
    {
        auto itl = s[i].lower_bound(l), itr = s[i].upper_bound(r);
        for (; itl != itr; ++itl)
        {
            s[i / v].insert(*itl);
            update(1, n, 1, *itl, i / v - i);
            tmp[++top] = *itl;
        }
        for (int i = 1; i <= top; ++i)
            s[i].erase(tmp[i]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        s[a[i]].insert(i);
    }
    build(1, n, 1);
    for (int i = 1; i <= m; ++i)
    {
        int op, l, r;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            if (v == 1)
                continue;
            update(l, r, v);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, n, 1, l, r));
        }
    }
    return 0;
}