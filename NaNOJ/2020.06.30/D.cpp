#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e1 + 5;
const ll mod = 998244353;
ll a[N][3];
ll pre[N], suf[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int j = 0; j < 3; ++j)
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        pre[i] = (pre[i - 1] * (1 - a[i][0] + mod) % mod + (pre[i - 1] + 1) * a[i][0] % mod) % mod;
    for (int i = n; i; --i)
        suf[i] = (suf[i + 1] * (1 - a[i][2] + mod) % mod + (suf[i + 1] + 1) * a[i][2] % mod) % mod;
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
        sum = (sum + pre[i - 1] * a[i][1] % mod * suf[i + 1] % mod) % mod;
    printf("%lld\n", sum % mod);
    return 0;
}