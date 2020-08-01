#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
set<int> s;
int dp[N][3];
#define tmin(a, b, c) (min((a), min((b), (c))))
void solve()
{
    int n, a, l;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        s.insert(a);
    }
    int t1, t2, t3;
    scanf("%d%d%d", &t1, &t2, &t3);
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = tmin(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + t1;
        if (i > 1)
            dp[i][1] = tmin(dp[i - 2][0], dp[i - 2][1], dp[i - 2][2]) + t1 + t2;
        else
            dp[i][1] = dp[i][2] = dp[i][0];
        if (i > 3)
            dp[i][2] = tmin(dp[i - 4][0], dp[i - 4][1], dp[i - 4][2]) + t1 + t2 * 3;
        else
            dp[i][2] = min(dp[i][0], dp[i][1]);
        if (s.find(i) != s.end())
        {
            dp[i][0] += t3;
            dp[i][1] += t3;
            dp[i][2] += t3;
        }
    }
    int ans = 0x7fffffff;
    ans = min(ans, dp[l][0]);
    ans = min(ans, dp[l][1]);
    ans = min(ans, dp[l][2]);
    ans = min(ans, dp[l + 1][1] - int(0.5 * (double)t2 + 0.5 * (double)t1));
    ans = min(ans, dp[l + 1][2] - int(0.5 * (double)t2 + 0.5 * (double)t1));
    ans = min(ans, dp[l + 2][2] - int(1.5 * (double)t2 + 0.5 * (double)t1));
    ans = min(ans, dp[l + 3][2] - int(2.5 * (double)t2 + 0.5 * (double)t1));
    printf("%d\n", ans);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}