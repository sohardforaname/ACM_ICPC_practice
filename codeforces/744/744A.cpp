#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
vector<int>G[MAXN];
int vis[MAXN];
int cap[MAXN], bu[MAXN];
void dfs(int fa, int u, int tag)
{
	vis[u] = tag;
	for (auto i : G[u])
		if (i != fa && !vis[i])
			dfs(u, i, tag);
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i)
		scanf("%d", &cap[i]);
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= k; ++i)
		dfs(0, cap[i], i);
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += (!vis[i]), ++bu[vis[i]];
	int maxn = 0;
	sort(bu + 1, bu + k + 1);
	int ans = 0;
	for (int i = 1; i < k; ++i)
		ans += bu[i] * (bu[i] - 1) / 2;
	ans += (bu[k] + sum) * (bu[k] + sum - 1) / 2;
	printf("%d\n", ans - m);
	return 0;
}