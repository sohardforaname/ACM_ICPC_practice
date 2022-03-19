#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
void solve()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll cnt = 0;
    for (ll i = 10; i - 1 <= m; i *= 10)
        ++cnt;
    printf("%lld\n", cnt * n);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}