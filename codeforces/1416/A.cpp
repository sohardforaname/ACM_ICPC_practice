#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N];
vector<int> G[N];
int maxn[N];
int tr[N << 2];
int pos[N];
void build(int l, int r, int k)
{
    if (l == r)
    {
        tr[k] = pos[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, k << 1);
    build(m + 1, r, (k << 1) + 1);
    tr[k] = min(tr[k << 1], tr[(k << 1) + 1]);
}
int query(int l, int r, int ql, int qr, int k)
{
    if (ql <= l && r <= qr)
        return tr[k];
    int ans = 0x3f3f3f3f, m = (l + r) >> 1;
    if (ql <= m)
        ans = min(ans, query(l, m, ql, qr, k << 1));
    if (qr > m)
        ans = min(ans, query(m + 1, r, ql, qr, (k << 1) + 1));
    return ans;
}
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        G[i].clear();
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), G[a[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        G[i].push_back(n + 1);
    memset(maxn, 0, sizeof(maxn[0]) * (n + 1));
    for (int i = 1; i <= n; ++i)
    {
        int pre = 0;
        for (auto j : G[i])
        {
            maxn[i] = max(maxn[i], j - pre);
            pre = j;
        }
    }
    memset(pos, 0x3f3f3f3f, sizeof(pos[0]) * (n + 1));
    for (int i = 1; i <= n; ++i)
        pos[maxn[i]] = min(pos[maxn[i]], i);
    build(1, n, 1);
    for (int i = 1; i <= n; ++i)
    {
        int ans = query(1, n, 1, i, 1);
        printf("%d%c", ans == 0x3f3f3f3f ? -1 : ans, " \n"[i == n]);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}