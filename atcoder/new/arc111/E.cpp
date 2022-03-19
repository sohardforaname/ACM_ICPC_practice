#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll a, ll b, ll c, ll n)
{
    if (a >= c || b >= c)
        return n * (n + 1) / 2 * (a / c) + (n + 1) * (b / c) + f(a % c, b % c, c, n);
    if (a == 0)
        return 0;
    return (a * n + b) / c * n - f(c, c - b - 1, a, (a * n + b) / c - 1);
}

int main()
{
    ll a, b, c, d;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        ll k = (d - 2) / (c - b);
        printf("%lld\n", k - f(c, a, d, k) + f(b, a - 1, d, k));
    }
    return 0;
}