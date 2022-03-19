#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N][N];
int dp[N];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n + m)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            for (int j = m; j >= 0; --j)
                for (int k = 1; k <= j; ++k)
                    dp[j] = max(dp[j], dp[j - k] + a[i][k]);
        printf("%d\n", dp[m]);
    }
    return 0;
}