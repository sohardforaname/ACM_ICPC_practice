#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int dfn[MAXN], low[MAXN];
bool cut[MAXN];
vector<int>G[MAXN];
int dfn_c;
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
				if (son > 1 || u != fa)
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
bool vis[MAXN];
int tag, cnt;
void dfs(int u)
{
	vis[u] = 1;
	++cnt;
	for (auto i : G[u])
		if (!vis[i] && i != tag)
			dfs(i);
}
#define mem(a,b,c) memset(a,b,sizeof(a[0])*(c+1))
void init(int n)
{
	for (int i = 1; i <= n; ++i)
		G[i].clear();
	mem(dfn, 0, n);
	mem(low, 0, n);
	mem(cut, 0, n);
	dfn_c = 0;
}
typedef long long ll;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, a, b, u, v;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		init(n);
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		tarjan(n);
		if (!cut[a] || !cut[b])
			printf("0\n");
		else
		{
			int x = 0, y = 0;
			tag = a, cnt = 0;
			mem(vis, 0, n);
			dfs(b);
			x = cnt;
			tag = b, cnt = 0;
			mem(vis, 0, n);
			dfs(a);
			y = cnt;
			printf("%lld\n", ll(n - x - 1) * ll(n - y - 1));
		}
	}
	return 0;
}