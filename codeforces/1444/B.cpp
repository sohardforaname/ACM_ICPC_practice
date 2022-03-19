#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
typedef long long ll;
const ll mod = 998244353;
ll a[N];
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n * 2 + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans - a[i] + mod) % mod;
    for (int i = n + 1; i <= 2 * n; ++i)
        ans = (ans + a[i]) % mod;
    ll fac2n = 1, facn = 1;
    for (int i = 1; i <= n; ++i)
        facn = facn * i % mod;
    fac2n = facn;
    for (int i = n + 1; i <= 2 * n; ++i)
        fac2n = fac2n * i % mod;
    printf("%lld\n", ans * fac2n % mod * pow(facn, mod - 2, mod) % mod * pow(facn, mod - 2, mod) % mod);
    return 0;
}