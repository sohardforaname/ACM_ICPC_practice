#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N], cnt[N], b[N];
ll sum[N];
int top;
set<ll> mp;
void dfs(int l, int r)
{
    mp.insert(sum[r] - sum[l - 1]);
    if (l == r)
        return;
    int m = upper_bound(a + 1, a + top + 1, (a[l] + a[r]) / 2) - a - 1;
    dfs(l, m);
    dfs(m + 1, r);
}
void solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    sort(a + 1, a + n + 1);
    top = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 1; i <= n; ++i)
        b[i] = lower_bound(a + 1, a + top + 1, b[i]) - a;
    for (int i = 1; i <= n; ++i)
        ++cnt[b[i]];
    for (int i = 1; i <= top; ++i)
        sum[i] = sum[i - 1] + 1ll * cnt[i] * a[i];
    dfs(1, top);
    for (int i = 1; i <= q; ++i)
    {
        ll s;
        scanf("%lld", &s);
        if (mp.find(s) != mp.end())
            puts("Yes");
        else
            puts("No");
    }
    for (int i = 1; i <= top; ++i)
        cnt[i] = 0;
    mp.clear();
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}