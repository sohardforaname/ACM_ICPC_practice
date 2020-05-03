#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int M = 4e4 + 5;
vector<int> G[N];
int dp[N][M];
pair<int, int> p[N], d[N];
int clk = 0, pre[N];
void dfs(int u) //后序遍历，求出dfs序
{
    int tp = clk;
    for (auto i : G[u])
        dfs(i);
    d[++clk] = p[u];
    pre[clk] = tp;
}
int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        p[i] = {a, a * b};
        G[c].push_back(i);
    }
    dfs(0);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            if (j >= d[i].first)
                dp[i][j] = max(dp[pre[i]][j], dp[i - 1][j - d[i].first] + d[i].second);
            else
                dp[i][j] = dp[pre[i]][j];
        }
    printf("%d\n", dp[n][m]);
    return 0;
}