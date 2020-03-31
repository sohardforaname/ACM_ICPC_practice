#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
vector<int>G[N];
bool use[N];
int par[N];
bool dfs(int u)
{
	for (auto i : G[u])
		if (!use[i])
		{
			use[i] = 1;
			if (!par[i] || dfs(par[i]))
			{
				par[i] = u;
				return 1;
			}
		}
	return 0;
}
int main()
{
	int k, n, m;
	while (scanf("%d", &k) && k)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			G[i].clear();
		memset(par, 0, sizeof(par[0]) * (m + 5));
		int u, v;
		for (int i = 1; i <= k; ++i)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			memset(use, 0, sizeof(use[0]) * (m + 5));
			if (dfs(i))
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}