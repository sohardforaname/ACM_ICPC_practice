#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, M = 1e3 + 5, K = 3e1 + 5;
int dp[M][K];
int v[N], w[N];
int a[K], b[K];
int main()
{
    int n, m, kth;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &kth);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            scanf("%d", &w[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &v[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = m; j >= v[i]; --j)
            {
                for (int k = 1; k <= kth; ++k)
                    a[k] = dp[j][k], b[k] = dp[j - v[i]][k] + w[i];
                a[kth + 1] = b[kth + 1] = -1;
                int x, y, pos;
                x = y = pos = 1;
                while (pos != kth + 1 && (a[x] != -1 || b[y] != -1))
                {
                    if (a[x] > b[y])
                        dp[j][pos] = a[x], ++x;
                    else
                        dp[j][pos] = b[y], ++y;
                    if (dp[j][pos] != dp[j][pos - 1])
                        ++pos;
                }
            }
        printf("%d\n", dp[m][kth]);
    }
    return 0;
}