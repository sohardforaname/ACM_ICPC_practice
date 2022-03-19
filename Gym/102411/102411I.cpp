#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main()
{
    ll minx = INF, miny = INF, maxx = -INF, maxy = -INF;
    ll n, a, b, c;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        minx = min(minx, a - c);
        miny = min(miny, b - c);
        maxx = max(maxx, a + c);
        maxy = max(maxy, b + c);
    }
    ll len = max(maxx - minx, maxy - miny);
    printf("%lld %lld %lld\n", maxx - len / 2, maxy - len / 2, (len + 1) / 2);
    return 0;
}