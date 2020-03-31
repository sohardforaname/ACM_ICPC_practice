#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
vector<int>G[MAXN], G1[MAXN], G2[MAXN];
int w[MAXN], w1[MAXN], tot[MAXN];
int dfn[MAXN], low[MAXN];
int scc[MAXN];
stack<int>s;
int vis[MAXN];
int scc_c, scc_cnt;
int indeg[MAXN];
void dfs(int u)
{
	dfn[u] = low[u] = ++scc_c;
	vis[u] = 1;
	s.push(u);
	for (auto i : G[u])
	{
		if (!vis[i])
		{
			dfs(i);
			low[u] = min(low[u], low[i]);
		}
		if (vis[i] == 1)
			low[u] = min(low[u], dfn[i]);
	}
	if (dfn[u] == low[u])
	{
		++scc_cnt;
		while (1)
		{
			int x = s.top();
			s.pop();
			scc[x] = scc_cnt;
			w1[scc_cnt] += w[x];
			vis[x] = 2;
			if (x == u)
				break;
		}
	}
}
void tarjan(int n)
{
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			dfs(i);
}
void topo(int n)
{
	queue<int>Q;
	for (int i = 1; i <= n; ++i)
		if (!indeg[i])
			Q.push(i), tot[i] = w1[i];
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (auto i : G1[u])
		{
			for (auto j : G2[i])
				tot[i] = max(tot[i], tot[j] + w1[i]);
			--indeg[i];
			if (!indeg[i])
				Q.push(i);
		}
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
	}
	tarjan(n);
	for (int i = 1; i <= n; ++i)
		for (auto j : G[i])
			if (scc[i] != scc[j])
			{
				G1[scc[i]].push_back(scc[j]);
				G2[scc[j]].push_back(scc[i]);
				++indeg[scc[j]];
			}
	topo(scc_cnt);
	printf("%d\n", *max_element(tot + 1, tot + scc_cnt + 1));
	return 0;
}
