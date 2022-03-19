#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int h[N];
ll sum[N];
int n, a, r, m;
ll calc(int x)
{
    int pos = lower_bound(h + 1, h + n + 1, x) - h - 1;
    ll c1 = 1ll * x * pos - sum[pos];
    ll c2 = sum[n] - sum[pos] - 1ll * x * (n - pos);
    ll res = min(c1, c2);
    return res * m + (c1 - res) * a + (c2 - res) * r;
}
int main()
{
    scanf("%d%d%d%d", &n, &a, &r, &m);
    m = min(m, a + r);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + h[i];
    ll ans = min(calc(sum[n] / n), calc(sum[n] / n + 1));
    for (int i = 1; i <= n; ++i)
        ans = min(ans, calc(h[i]));
    printf("%lld\n", ans);
    return 0;
}