#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int dx[6] = {1, 0, -1, -1, 0, 1};
int dy[6] = {1, 1, 0, -1, -1, 0};
void solve()
{
    ll x, y;
    ll c1, c2, c3, c4, c5, c6;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x, &y, &c1, &c2, &c3, &c4, &c5, &c6);
    ll ans = 0;
    if (x >= 0 && y >= 0)
    {
        ans = min({c6 * x + c2 * y, c1 * x + (y - x >= 0 ? c2 * (y - x) : c5 * (x - y))});
        ans = min({ans, (y <= x ? c1 * y + c6 * (x - y) : c1 * y + c3 * (y - x))});
    }
    else if (x < 0 && y >= 0)
    {
        ans = min({c3 * (-x) + c2 * y, c4 * (-x) + c2 * (y - x)});
        ans = min({ans, c2 * y + c3 * (-x), c3 * (y - x) + c1 * y});
    }
    else if (x >= 0 && y < 0)
    {
        ans = min({c6 * x + c5 * (-y), c1 * x + c5 * (x - y)});
        ans = min({ans, c6 * x + c5 * (-y), c6 * (x - y) + c4 * (-y)});
    }
    else if (x < 0 && y < 0)
    {
        ans = min({c3 * (-x) + c5 * (-y), c4 * (-x) + (y - x >= 0 ? c2 * (y - x) : c5 * (x - y))});
        ans = min({ans, (y >= x ? c4 * (-y) + c3 * (y - x) : c4 * (-y) + c6 * (x - y))});
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