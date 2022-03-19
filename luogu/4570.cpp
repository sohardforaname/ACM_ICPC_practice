#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
ll d[65];
pair<ll, int> a[N];
bool add(ll x)
{
    for (int i = 63; ~i; --i)
    {
        if (x & (1ll << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
bool cmp(pair<ll, int> &a, pair<ll, int> &b)
{
    return a.second > b.second;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%d", &a[i].first, &a[i].second);
    sort(a + 1, a + n + 1, cmp);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        if (add(a[i].first))
            ans += a[i].second;
    printf("%lld\n", ans);
    return 0;
}