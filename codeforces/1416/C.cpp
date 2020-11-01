#include <bits/stdc++.h>
using namespace std;
double dp[10][10], sum[10][10], rt[10][10];
double a[10], b[10];
int main()
{
    for (int i = 1; i <= 7; ++i)
        scanf("%lf", &a[i]);
    for (int i = 0; i <= 7; ++i)
        scanf("%lf", &b[i]);
    for (int i = 1; i <= 8; ++i)
    {
        dp[i][i - 1] = b[i - 1];
        sum[i][i - 1] = b[i - 1];
    }
    for (int l = 1; l <= 7; ++l)
        for (int i = 1; i <= 7 - l + 1; ++i)
        {
            int j = i + l - 1;
            dp[i][j] = 0x3f3f3f3f;
            sum[i][j] = sum[i][j - 1] + a[j] + b[j];
            for (int k = i; k <= j; ++k)
                if (dp[i][j] > dp[i][k - 1] + dp[k + 1][j] + sum[i][j])
                {
                    dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + sum[i][j];
                    rt[i][j] = k;
                }
        }
    return 0;
}