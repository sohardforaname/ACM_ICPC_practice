#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int sz[N], son[N], dis[N], s[N];
bool vis[N];
vector<pair<int, int> >G[N];
int n, top, k, maxn, rt, siz, m;
int buc[10000005];
int query[105], ans[105];
void getroot(int u, int fa)
{
	sz[u] = 1, son[u] = 0;
	for (auto i : G[u])
	{
		if (vis[i.first] || i.first == fa)
			continue;
		getroot(i.first, u);
		sz[u] += sz[i.first];
		if (son[u] < sz[i.first])
			son[u] = sz[i.first];
	}
	if (son[u] < siz - sz[u])
		son[u] = siz - sz[u];
	if (son[u] < maxn)
		maxn = son[u], rt = u;
}
void getdis(int u, int fa)
{
	s[++top] = dis[u];
	for (auto i : G[u])
	{
		if (vis[i.first] || i.first == fa)
			continue;
		dis[i.first] = dis[u] + i.second;
		getdis(i.first, u);
	}
}
void solve(int u, int d, int c)
{
	top = 0;
	dis[u] = d;
	getdis(u, 0);
	for (int i = 1; i <= top; ++i)
		if (s[i] < 1e7 + 1)
			++buc[s[i]];
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= top; ++j)
			if (query[i] >= s[j])
				ans[i] += buc[query[i] - s[j]] * c;
	for (int i = 1; i <= top; ++i)
		if (s[i] < 1e7 + 1)
			--buc[s[i]];
}
void dfs(int u)
{
	vis[u] = 1;
	solve(u, 0, 1);
	for (auto i : G[u])
	{
		if (vis[i.first])
			continue;
		solve(i.first, i.second, -1);
		maxn = 0x3f3f3f3f;
		rt = 0;
		siz = sz[i.first] > sz[u] ? n - sz[u] : sz[i.first];
		getroot(i.first, u);
		dfs(rt);
	}
}
int main()
{
	int a, b, c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	for (int i = 1; i <= m; ++i)
		scanf("%d", &query[i]);
	maxn = 0x3f3f3f3f, rt = 0, siz = n;
	getroot(1, 0);
	dfs(rt);
	for (int i = 1; i <= m; ++i)
	{
		if (ans[i])
			printf("AYE\n");
		else
			printf("NAY\n");
	}
	return 0;
}