#include <bits/stdc++.h>
using namespace std;
int dp[20][2]; //第i是j的情况
int a[20];
int dfs(int pos, int pre, bool lim, bool tag) //这一位的数字，上一位数字，上限，6的标记
{
    if (pos == -1) //已经到尽头了
        return 1;
    if (!lim && dp[pos][tag] != -1) //记忆化搜索，一定要判断是否有边界，有边界时计算不存在情况。
        return dp[pos][tag];
    int res = lim ? a[pos] : 9; //设置边界
    int ans = 0;
    for (int i = 0; i <= res; ++i)
    {
        if (i == 4 || (i == 2 && pre == 6))
            continue;
        ans += dfs(pos - 1, i, lim && i == a[pos], i == 6); //有边界且i到达了边界，下一位也才有边界
    }
    if (!lim)
        dp[pos][tag] = ans; //记录
    return ans;
}
int solve(int num)
{
    memset(a, 0, sizeof(a));
    int pos = 0;
    while (num)
    {
        a[pos++] = num % 10;
        num /= 10;
    }
    return dfs(pos - 1, 0, true, 0); //刚开始的时候一定有边界
}
int main()
{
    int n, m;
    while (cin >> n >> m && n + m)
    {
        memset(dp, -1, sizeof(dp));
        cout << solve(m) - solve(n - 1) << endl;
    }
    return 0;
}
