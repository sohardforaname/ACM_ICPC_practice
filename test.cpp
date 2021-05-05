#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cnt1 = 0, ans = 0;
const ll mod = 1e9 + 7;

ll mul(ll a, ll b, ll p)
{
    ll res = 0;
    while (b) {
        if (b & 1) {
            res = (res + a) % p;
        }
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}
int main(int argc, char** argv)
{
    freopen("D:\\4.3-data\\1.out", "r", stdin);
    ll a;
    while (~scanf("%lld", &a)) {
        ans = (ans + mul(a, ++cnt1, mod)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}