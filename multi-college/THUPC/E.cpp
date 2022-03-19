#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
const ll mod = 998244353;
ll dp[N][20];
bool vis[20];
ll cal(int c, int v, int n)
{
    //printf("%x\n", v);
    int sum = (1 << c);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < sum; ++i)
        vis[i] = (v >> (sum - i - 1)) & 1;
    memset(dp, 0, sizeof(dp));
    dp[sum][v & (sum - 1)] = 1;
    for (int i = sum + 1; i <= n; ++i)
        for (int j = 0; j < sum; ++j)
        {
            if (vis[(j >> 1) + (1 << (c - 1))])
                dp[i][j] = (dp[i][j] + dp[i - 1][(j >> 1) + (1 << (c - 1))]) % mod;
            if (vis[j >> 1])
                dp[i][j] = (dp[i][j] + dp[i - 1][j >> 1]) % mod;
        }
    ll ans = 0;
    for (int i = 0; i < (1 << c); ++i)
        if (vis[i])
            ans = (ans + dp[n][i]) % mod;
    return ans % mod;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int j = 1 << k;
    ll ans = 0;
    for (int v = 0; v < (1 << j); ++v)
    {
        bool f = 1;
        for (int l = 0; l <= j - k; ++l)
        {
            int tmp = (v >> (j - k - l)) & (j - 1);
            if (((v >> (j - tmp - 1)) & 1) == 0)
                f = 0;
        }
        if (f)
            ans = (ans + cal(k, v, n)) % mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}
