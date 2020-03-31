#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t int128;
ll mul(ll a, ll b, ll p) //大数乘
{
    int128 _a = a, _b = b, _p = p;
    return ll(_a * _b % _p);
}
ll inv(ll a, ll b, ll p) //快速幂
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return res;
}
ll check(ll x)
{
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    ll p, q, ans;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> p;
        q = p - 2, ans = 1;
        while (!check(q))
        {
            ans = mul(ans, inv(q, p - 2, p), p);
            --q;
        }
        cout << ans << endl;
    }
    return 0;
}
