#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
vector<int>G[MAXN];
int sum[MAXN];
ll ans[MAXN];
bool cut[MAXN];
int dfn[MAXN], low[MAXN];
int dfn_c;
int cnt[MAXN];
ll n, m;
void dfs(int fa, int u)
{
	dfn[u] = low[u] = ++dfn_c;
	int ch = 0;
	cnt[u] = 1;
	for (auto i : G[u])
	{
		if (i == fa)
			continue;
		if (!dfn[i])
		{
			dfs(u, i);
			cnt[u] += cnt[i];
			low[u] = min(low[u], low[i]);
			if (low[i] >= dfn[u])
			{
				sum[u] += cnt[i];
				ans[u] += cnt[i] * (n - cnt[i]);
				++ch;
				if (ch > 1 || u != fa)
					cut[u] = 1;
			}
		}
		else
			low[u] = min(low[u], dfn[i]);
	}
	if (cut[u])
		ans[u] += (sum[u] + 1) * (n - sum[u] - 1) + (n - 1);
	else
		ans[u] = 2 * (n - 1);
}
void tarjan(int n)
{
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			dfs(i, i);
}
int main()
{
	int a, b;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	tarjan(n);
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}
