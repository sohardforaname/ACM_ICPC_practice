#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int M = 5e3 + 5;
struct good
{
    int p, q, v;
    bool operator<(const good &a) const
    {
        return q - p < a.q - a.p;
    }
};
good g[N];
int dp[M];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        memset(dp, 0, sizeof(dp[0]) * (m + 1));
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &g[i].p, &g[i].q, &g[i].v);
        sort(g + 1, g + n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = m; j >= max(g[i].q, g[i].p); --j)
                dp[j] = max(dp[j], dp[j - g[i].p] + g[i].v);
        printf("%d\n", dp[m]);
    }
    return 0;
}