#include <bits/stdc++.h>
using namespace std;
struct good
{
    int w, c;
};
good g[15];
int dp[5000005];
int main()
{
    int s, n, d;
    scanf("%d%d%d", &s, &n, &d);
    for (int i = 1; i <= d; ++i)
        scanf("%d%d", &g[i].w, &g[i].c);
    for (int i = 1; i <= n; ++i)
    {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= d; ++j)
            for (int k = g[j].w; k <= s; ++k)
                dp[k] = max(dp[k], dp[k - g[j].w] + g[j].c);
        s += dp[s];
    }
    printf("%d\n", s);
    return 0;
}