#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
const int M = 1e5 + 5;
int dp[N][M];
int box[N], cnt[N];
pair<int, int> p[N][15];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &box[i], &cnt[i]);
            for (int j = 1; j <= cnt[i]; ++j)
                scanf("%d%d", &p[i][j].first, &p[i][j].second);
        }
        memset(dp, -1, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= cnt[i]; ++j)
                for (int k = m; k >= p[i][j].first; --k)
                {
                    if (dp[i][k - p[i][j].first] != -1)
                        dp[i][k] = max(dp[i][k], dp[i][k - p[i][j].first] + p[i][j].second);
                    if (k >= box[i] + p[i][j].first && dp[i - 1][k - box[i] - p[i][j].first] != -1)
                        dp[i][k] = max(dp[i][k], dp[i - 1][k - box[i] - p[i][j].first] + p[i][j].second);
                }
            for (int j = 0; j <= m; ++j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}