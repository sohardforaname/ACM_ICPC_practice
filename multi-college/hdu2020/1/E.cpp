#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 9;
ll fac[N], inv[N];
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    a %= mod;
    if (b > mod)
        b = b % (mod - 1) + mod - 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = pow(fac[n], mod - 2, mod);
    for (int i = n - 1; ~i; --i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
ll C(ll n, ll m)
{
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
ll x1, x2;
int main()
{
    init(1e5);
    int T;
    scanf("%d", &T);
    ll inv2 = pow(2, mod - 2, mod);
    x1 = (383008016 + 1) * inv2 % mod;
    x2 = (616991993 + 1) * inv2 % mod;
    ll d = pow(383008016, mod - 2, mod);
    while (T--)
    {
        ll n, c, k;
        scanf("%lld%lld%lld", &n, &c, &k);
        ll ans = 0;
        ll A = pow(x1, c, mod); //A
        ll B = pow(x2, c, mod); //B
        ll ainv = pow(A, mod - 2, mod);
        ll ai = pow(A, k, mod);
        ll bi = 1;
        for (int i = 0; i <= k; ++i)
        {
            ll q = ai * bi % mod, tmp;
            if (q == 1)
                tmp = (n + 1) % mod;
            else
                tmp = (pow(q, n + 1, mod) - 1 + mod) % mod * pow(q - 1, mod - 2, mod) % mod;
            tmp = tmp * C(k, i) % mod;
            if (i & 1)
                ans = (ans - tmp + mod) % mod;
            else
                ans = (ans + tmp) % mod;
            ai = ai * ainv % mod;
            bi = bi * B % mod;
        }
        ans = ans * pow(d, k, mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}