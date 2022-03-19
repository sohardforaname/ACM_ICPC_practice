#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const ll MOD = 998244353;
ll p[N];
int main()
{
    ll n;
    scanf("%lld", &n);
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] * 10 % MOD;
    for (ll i = 1; i < n; ++i)
        printf("%lld ", (18 * p[n - i] % MOD + ((n - i - 1) * 81 % MOD) * p[n - i - 1] % MOD) % MOD);
    printf("10\n");
    return 0;
}