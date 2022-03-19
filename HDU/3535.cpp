#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int t[N], h[N];
int dp[N][N];
int main()
{
    int n, T;
    while (~scanf("%d%d", &n, &T))
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            int m, s;
            scanf("%d%d", &m, &s);
            for (int j = 1; j <= m; ++j)
                scanf("%d%d", &t[j], &h[j]);
            if (s == 0) //至少一个
            {
                for (int j = 0; j <= T; ++j)
                    dp[i][j] = -0x3f3f3f3f;
                for (int j = 1; j <= m; ++j)
                    for (int k = T; k >= t[j]; --k)
                        //前面一个是假定前面没选第i组，选j；后面一个是假定前面选了第i组j前面的，现在多选一个j
                        dp[i][k] = max(dp[i][k], max(dp[i - 1][k - t[j]] + h[j], dp[i][k - t[j]] + h[j]));
            }
            else if (s == 1) //至多一个
            {
                for (int j = 0; j <= T; ++j)
                    dp[i][j] = dp[i - 1][j];
                for (int j = 1; j <= m; ++j)
                    for (int k = T; k >= t[j]; --k)
                        dp[i][k] = max(dp[i][k], dp[i - 1][k - t[j]] + h[j]);
            }
            else //随意
            {
                for (int j = 0; j <= T; ++j)
                    dp[i][j] = dp[i - 1][j];
                for (int j = 1; j <= m; ++j)
                    for (int k = T; k >= t[j]; --k)
                        dp[i][k] = max(dp[i][k], dp[i][k - t[j]] + h[j]);
            }
        }
        printf("%d\n", max(dp[n][T], -1));
    }
    return 0;
}