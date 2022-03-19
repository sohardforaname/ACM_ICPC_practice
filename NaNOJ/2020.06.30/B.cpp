#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
struct BIT
{
    ll c[N];
    void init()
    {
        memset(c, 0, sizeof(c));
    }
    void update(int p, ll v, int n)
    {
        for (; p <= n; p += p & (-p))
            c[p] = max(c[p], v);
    }
    ll query(int p)
    {
        ll ans = 0;
        for (; p; p -= p & (-p))
            ans = max(ans, c[p]);
        return ans;
    }
};
BIT tr;
pair<ll, ll> p[N];
int a[N], dp[N];
ll c[N];
int n, k;
bool check(int x)
{
    tr.init();
    for (int i = 1; i <= n; ++i)
        p[i] = {1ll * i * x + a[i], 1ll * i * x - a[i]};
    for (int i = 1; i <= n; ++i)
        c[i] = p[i].second;
    sort(c + 1, c + n + 1);
    int top = unique(c + 1, c + n + 1) - c - 1;
    for (int i = 1; i <= n; ++i)
        p[i].second = lower_bound(c + 1, c + top + 1, p[i].second) - c;
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = tr.query(p[i].second) + 1;
        tr.update(p[i].second, dp[i], n);
    }
    int maxn = 0;
    for (int i = 1; i <= n; ++i)
        maxn = max(maxn, dp[i]);
    return maxn >= n - k;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    ll l = 0, r = 2e9;
    while (l < r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    printf("%lld\n", l);
    return 0;
}