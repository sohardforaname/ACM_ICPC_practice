#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 4e3 + 5;
int dp[2][N][2];
int a[N];
int main()
{
    int n, b;
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(dp, 0xcf, sizeof(dp));
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
        {
            dp[i % 2][j][0] = max(dp[(i - 1) % 2][j][0], dp[(i - 1) % 2][j][1]);
            if (j > 0)
                dp[i % 2][j][1] = max(dp[(i - 1) % 2][j - 1][1] + a[i], dp[(i - 1) % 2][j - 1][0]);
        }
    int maxn = max(dp[n % 2][b][0], dp[n % 2][b][1]);
    memset(dp, 0xcf, sizeof(dp));
    dp[1][1][1] = a[1];
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
        {
            dp[i % 2][j][0] = max(dp[(i - 1) % 2][j][0], dp[(i - 1) % 2][j][1]);
            if (j > 0)
                dp[i % 2][j][1] = max(dp[(i - 1) % 2][j - 1][1] + a[i], dp[(i - 1) % 2][j - 1][0]);
        }
    maxn = max(maxn, dp[n % 2][b][1]);
    printf("%d\n", maxn);
    return 0;
}