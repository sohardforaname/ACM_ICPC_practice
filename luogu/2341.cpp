#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;
vector<int>G[MAXN];
int dfn[MAXN], low[MAXN], vis[MAXN];
int scc_c, scc_cnt;
int cnt[MAXN];
int deg[MAXN], scc[MAXN];
stack<int>s;
void dfs(int u)
{
	dfn[u] = low[u] = ++scc_c;
	vis[u] = 1;//necessary
	s.push(u);
	for (auto i : G[u])
	{
		if (!vis[i])
		{
			dfs(i);
			low[u] = min(low[u], low[i]);
		}
		else if (vis[i] == 1)
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
			++cnt[scc_cnt];
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
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
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
				++deg[scc[i]];
	int ans = 0, p;
	for (int i = 1; i <= scc_cnt; ++i)
		if (!deg[i])
			++ans, p = i;
	if (ans == 1)
		printf("%d\n", cnt[p]);
	else
		printf("0\n");
	return 0;
}