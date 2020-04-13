#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 5;
ll dp[N][2];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    dp[1][0] = dp[k][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][0] += dp[i][1];
        dp[i + k][0] += dp[i][1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dp[i][0];
    printf("%lld\n", ans);
    system("pause");
    return 0;
}