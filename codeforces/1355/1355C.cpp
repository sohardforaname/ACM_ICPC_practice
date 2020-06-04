#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll sum[N];
int a, b, c, d;
int main()
{
    ll ans = 0;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = a + b; i <= b + c; ++i)
    {
        if (i <= c)
            continue;
        int minz = min(i, c), maxz = min(i - 1, d);
        int miny = max(i - b, b), maxy = min(i - a, c);
        ans += (maxz - minz + 1ll) * (maxy - miny + 1ll);
    }
    printf("%lld\n", ans);
    return 0;
}