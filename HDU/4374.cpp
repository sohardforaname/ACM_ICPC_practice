#include <bits/stdc++.h>
using namespace std;
int dp[10][5000], a[10];
int all;
int dfs(int pos, int sum, bool lim)
{
    if (pos == -1)
        return sum <= all;
    if (all < sum)
        return 0;
    if (!lim && dp[pos][all - sum] != -1)
        return dp[pos][all - sum];
    int ans = 0;
    int res = lim ? a[pos] : 9;
    for (int i = 0; i <= res; ++i)
        ans += dfs(pos - 1, sum + i * (1 << pos), lim && i == a[pos]);
    if (!lim)
        dp[pos][all - sum] = ans;
    return ans;
}
int f(int x)
{
    int ans = 0, pos = 1;
    while (x)
    {
        ans += (x % 10) * pos;
        pos <<= 1;
        x /= 10;
    }
    return ans;
}
int solve(int x)
{
    int pos = 0;
    while (x)
    {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, true);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    memset(dp, -1, sizeof(dp)); //״̬����һֱʹ�ã�������λ���Ʊ仯
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        all = f(a);
        cout << "Case #" << i << ": " << solve(b) << endl;
    }
    return 0;
}
