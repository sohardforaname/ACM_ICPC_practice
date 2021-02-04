#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
ll div(ll n)
{
    if (n == 1)
        return n;
    ll tmp = a;
    while (tmp % b == 0)
        tmp /= n;
    return tmp;
}
void solve()
{
    scanf("%lld%lld", &a, &b);
    if (a % b)
        return void(printf("%lld\n", a));
    ll ans = 0;
    for (int i = 1; i <= sqrt(b); ++i)
        if (b % i == 0)
            ans = max({ans, div(i), div(b / i)});
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