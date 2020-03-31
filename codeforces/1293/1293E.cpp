#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
typedef long long ll;
int par[N][N], sub[N][N];
ll dp[N][N];
vector<int>G[N];
void dfs(int u, int fa, int rt)
{
	sub[rt][u] = 1;
	par[rt][u] = fa;
	for (auto i : G[u])
	{
		if (i == fa)
			continue;
		dfs(i, u, rt);
		sub[rt][u] += sub[rt][i];
	}
}
ll dfs2(int u, int v)
{
	if (u == v)
		return 0;
	else if (dp[u][v] != -1)
		return dp[u][v];
	return dp[u][v] = sub[u][v] * sub[v][u] + max(dfs2(par[v][u], v), dfs2(u, par[u][v]));
}
ll cal(int n)
{
	for (int i = 1; i <= n; ++i)
		dfs(i, 0, i);
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ans = max(ans, dfs2(i, j));
	return ans;
}
int main()
{
	int n, u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	return printf("%lld\n", cal(n)), 0;
}
