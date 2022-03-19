#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 5;
const ll mod = 998244353;
ll fac[N];
ll fac1[N];
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
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 1e7; ++i)
        fac[i] = fac[i - 1] * i % mod;
    fac1[0] = 1;
    for (int i = 1; i <= 1e7; ++i)
        fac1[i] = fac1[i - 1] * (i * 2 - 1) % mod;
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n / 2; ++i)
            printf("0 ");
        int tmp = n / 2;
        int l = 1, r = n / 2;
        ll fm = pow(fac[tmp] * pow(2, tmp, mod) % mod, mod - 2, mod);
        ll e = 1;
        for (int i = 0; i < n / 2; ++i)
        {
            e = fac1[i] * fac[r] % mod * pow(fac[l - 1], mod - 2, mod) % mod * fm % mod;
            printf("%lld ", e);
            l += 2, ++r;
        }
        printf("%lld\n", e);
    }
    return 0;
}