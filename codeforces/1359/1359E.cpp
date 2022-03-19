#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const ll mod = 998244353;
ll c[N];
ll qpow(ll a, ll b, ll p)
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
void init(int k, int n)
{
    c[k] = 1;
    for (int i = k + 1; i <= n; ++i)
    {
        c[i] = c[i - 1] * i % mod;
        c[i] = c[i] * qpow(i - k, mod - 2, mod) % mod;
    }
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    init(k - 1, n);
    ll ans = 0;
    for (int i = 1; i <= n / k; ++i)
        ans = (ans + c[n / i - 1]) % mod;
    printf("%lld\n", ans);
    return 0;
}