#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int M = 2e3 + 5;
int a[N], b[N];
int dp[N][N];
int main()
{
    int n, m, t, s;
    while (~scanf("%d%d%d%d", &n, &m, &t, &s))
    {
        for (int i = 1; i <= t; ++i)
            scanf("%d%d", &a[i], &b[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= t; ++i)
            for (int j = b[i]; j <= m; ++j)
                for (int k = 1; k <= s; ++k)
                    dp[j][k] = max(dp[j][k], dp[j - b[i]][k - 1] + a[i]);
        int ans = 0x3f3f3f3f;
        for (int j = m; j >= 0; --j)
            for (int k = s; k >= 0; --k)
                if (dp[j][k] >= n)
                    ans = min(ans, j);
        if (ans == 0x3f3f3f3f)
            printf("-1\n");
        else
            printf("%d\n", m - ans);
    }
    return 0;
}