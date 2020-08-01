#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5, M = 1e1 + 5;
const ll mod = 1e9 + 7;
ll dp[M][N], sum[N];
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        dp[1][i] = n - i;
    for (int i = 2; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = j; k < n; ++k)
                dp[i][j] = (dp[i][j] + dp[i - 1][k] * (k - j + 1)) % mod;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + dp[m][i]) % mod;
    printf("%lld\n", ans);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}