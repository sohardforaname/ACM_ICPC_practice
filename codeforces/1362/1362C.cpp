#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll num[80];
void init()
{
    num[0] = 1;
    for (int i = 1; i <= 64; ++i)
        num[i] = num[i - 1] + (1ull << i);
}
void solve()
{
    ll n;
    scanf("%llu", &n);
    ll ans = 0;
    for (int i = 0; n; n >>= 1, ++i)
        if (n & 1)
            ans += num[i];
    printf("%llu\n", ans);
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}