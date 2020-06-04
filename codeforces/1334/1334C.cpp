#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
typedef long long ll;
pair<ll, ll> a[N << 1];
ll c[N << 1];
#define x first
#define y second
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        a[i + n] = a[i];
    }
    for (int i = 2; i <= (n << 1); ++i)
        c[i] = max(0ll, a[i].x - a[i - 1].y) + c[i - 1];
    ll ans = 1e18;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, a[i].x + c[i + n - 1] - c[i]);
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
