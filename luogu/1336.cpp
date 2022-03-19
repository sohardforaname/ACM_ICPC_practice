#include <bits/stdc++.h>
using namespace std;
const int N = 200,
          M = 20;
typedef long long ll;
ll v[M][N];
int a[M], b[M];
ll dp[N];
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &a[i], &b[i]);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[j][i] = a[j] * qpow(i, b[j]);
    for (int i = 1; i <= m; ++i)
        for (int j = n; j >= 1; --j)
            for (int k = 1; k <= j; ++k)
                dp[j] = min(dp[j], dp[j - k] + v[i][k]);
    printf("%lld", dp[n]);
    return 0;
}