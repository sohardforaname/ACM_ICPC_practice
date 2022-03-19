#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 5;
const ll mod = 1e9 + 7;
int dp[N][N];
char mat[N][N];
int sum[N][N];
int a[N], n;
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]), --a[i];
    for (int i = 0; i < n; ++i)
        scanf("%s", mat[i]);
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
            {
                sum[j + 1][k + 1] = mat[a[j]][a[i]] == '1' ? dp[j][k] : 0;
                sum[j + 1][k + 1] = (sum[j + 1][k + 1] + sum[j + 1][k]) % mod;
                sum[j + 1][k + 1] = (sum[j + 1][k + 1] + sum[j][k + 1]) % mod;
                sum[j + 1][k + 1] = (sum[j + 1][k + 1] - sum[j][k] + mod) % mod;
            }
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (a[i] == a[j] && a[i] == a[k])
                {
                    int tmp = (sum[j][k] + 1) % mod;
                    dp[j][k] = (dp[j][k] + tmp) % mod;
                    ans = (ans + tmp) % mod;
                }
    }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}