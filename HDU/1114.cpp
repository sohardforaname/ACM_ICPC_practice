#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int M = 1e4 + 5;
int dp[M];
int p[N], w[N];
void solve()
{
    int n;
    int e, f;
    scanf("%d%d", &e, &f);
    f -= e;
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp[0]) * (f + 1));
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i], &w[i]);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= f; ++j)
            dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
    if (dp[f] < 0x3f3f3f3f)
        printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f]);
    else
        printf("This is impossible.\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}