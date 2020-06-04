#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld", pow((pow(2, m, mod) - 1ll + mod) % mod, n, mod));
    return 0;
}