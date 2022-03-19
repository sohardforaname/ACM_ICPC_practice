#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1.1e3 + 5;
const ll mod = 1e9 + 7;
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
ll fac[N];
void solve()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % mod;
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld\n", fac[n + 2 * m - 1] * pow(fac[n - 1], mod - 2, mod) % mod * pow(fac[2 * m], mod - 2, mod) % mod);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}