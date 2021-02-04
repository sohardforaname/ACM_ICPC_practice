#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
typedef long long ll;
int a[N], b[N];
int dp[N][N * N];
int main()
{
    int n;
    scanf("%d", &n);
    int suma = 0, sumb = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a + i, b + i);
        suma += a[i], sumb += b[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j >= 1; --j)
            for (int k = suma; k >= a[i]; --k)
                dp[j][k] = max(dp[j][k], dp[j - 1][k - a[i]] + b[i]);
    for (int i = 1; i <= n; ++i)
    {
        double maxn = 0;
        for (int j = 0; j <= suma; ++j)
            maxn = max(maxn, min(1.0 * j, (sumb + dp[i][j]) / 2.0));
        printf("%.9f%c", maxn, " \n"[i == n]);
    }
    return 0;
}