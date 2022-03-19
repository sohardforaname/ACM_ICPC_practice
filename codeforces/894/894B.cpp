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
    int k;
    scanf("%lld%lld%d", &n, &m, &k);
    if ((n + m) % 2 && k == -1)
    {
        printf("0\n");
        return 0;
    }
    printf("%lld\n", pow(pow(2, n - 1, mod), m - 1, mod));
    return 0;
}