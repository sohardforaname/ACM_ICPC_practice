#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
pair<ll, ll> p[N];
int getdir(ll s, ll t)
{
    if (s == t)
        return 0;
    else if (s > t)
        return -1;
    return 1;
}
bool inrange(ll l, ll r, ll pos)
{
    if (l > r)
        swap(l, r);
    return l <= pos && pos <= r;
}
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &p[i].first, &p[i].second);
    p[n + 1].first = 1e18;
    ll pos = 0, ans = 0;
    for (int i = 1; i <= n;)
    {
        int dir = getdir(pos, p[i].second);
        int nxt = i + 1;
        while (nxt <= n && p[nxt].first < abs(p[i].second - pos) + p[i].first)
            ++nxt;
        for (int j = i; j < nxt; ++j)
        {
            ll l = pos + dir * (p[j].first - p[i].first);
            ll r = pos + dir * (p[j + 1].first - p[i].first);
            if (dir == -1)
                l = max(l, p[i].second), r = max(r, p[i].second);
            else
                l = min(l, p[i].second), r = min(r, p[i].second);
            if (inrange(l, r, p[j].second))
                ++ans;
        }
        pos = p[i].second;
        i = nxt;
    }
    printf("%lld\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}