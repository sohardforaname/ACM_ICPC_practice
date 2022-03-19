#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int dfn[MAXN], low[MAXN];
bool cut[MAXN];
int dfn_c;
vector<int>G[MAXN];
int a, b;
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
			if (u != fa && low[i] >= dfn[u] && dfn[i] <= dfn[b])
				cut[u] = 1;
		}
		else
			low[u] = min(low[u], dfn[i]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (scanf("%d%d", &a, &b) && a + b)
	{
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d%d", &a, &b);
	dfs(a, a);
	int f = 0;
	for (int i = 1; i <= n; ++i)
		if (cut[i])
		{
			f = i;
			break;
		}
	if (!f)
		printf("No solution\n");
	else
		printf("%d\n", f);
	return 0;
}