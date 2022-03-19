#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N], n;
ll dp[N];
ll dfs(int pos)
{
    if (pos >= n + 1)
    {
        if (pos == n + 1)
            return 0;
        else
            return 1e18;
    }
    if (dp[pos] != -1)
        return dp[pos];
    return dp[pos] = min(dfs(pos + 4) + a[pos + 3] - a[pos], dfs(pos + 6) + a[pos + 5] - a[pos]);
}
void solve()
{
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp[0]) * (n + 1));
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    printf("%lld\n", dfs(1) * 2);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}