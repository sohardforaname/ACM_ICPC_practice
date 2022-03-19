#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+ 5;
typedef long long ll; 
vector<int>G[N];
int a[N], dp[N], ans[N];
void dfs(int u, int fa)
{
	for (auto i : G[u])
		if (i != fa)
		{
			dfs(i, u);
			dp[u] += max(0, dp[i]);
		}
	dp[u] += a[u];
}
void dfs2(int u, int fa)
{
	ans[u] = dp[u];
	for (auto i : G[u])
	{
		if (i != fa)
		{
			dp[u] -= max(0, dp[i]);
			dp[i] += max(0, dp[u]);
			dfs2(i, u);
			dp[i] -= max(0, dp[u]);
			dp[u] += max(0, dp[i]);
		}
	}
}
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if (!a[i])
			--a[i];
	}
	int u, v;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], " \n"[i == n]);
}
int main()
{
	int T = 1;
	//scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}