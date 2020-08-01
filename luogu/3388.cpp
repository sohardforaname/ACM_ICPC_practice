#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
vector<int> G[MAXN];
int dfn[MAXN], low[MAXN];
int dfn_c;
bool cut[MAXN];
void dfs(int fa, int u)
{
	dfn[u] = low[u] = ++dfn_c;
	int son = 0;
	for (auto i : G[u])
	{
		if (i == fa)
			continue;
		if (!dfn[i])
		{
			dfs(u, i);
			low[u] = min(low[u], low[i]);
			if (low[i] >= dfn[u])
			{
				++son;
				if (u != fa || son > 1)
					cut[u] = 1;
			}
		}
		else
			low[u] = min(low[u], dfn[i]);
	}
}
void tarjan(int n)
{
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			dfs(i, i);
}
int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	tarjan(n);
	int tot = 0;
	for (int i = 1; i <= n; ++i)
		if (cut[i])
			++tot;
	printf("%d\n", tot);
	for (int i = 1; i <= n; ++i)
		if (cut[i])
			printf("%d ", i);
	printf("\n");
	return 0;
}