#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 3;
typedef long long ll;
int a[N];
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
void solve()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    ll ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!ans1 && !ans2)
        {
            ans1 = (ans1 + qpow(p, a[i], mod)) % mod;
            ans2 = (ans2 + qpow(p, a[i], mod1)) % mod1;
        }
        else
        {
            ans1 = (ans1 - qpow(p, a[i], mod) + mod) % mod;
            ans2 = (ans2 - qpow(p, a[i], mod1) + mod1) % mod1;
        }
    }
    printf("%lld\n", (ans1 + mod) % mod);
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}