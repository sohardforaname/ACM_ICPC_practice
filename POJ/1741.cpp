#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int sz[N], dis[N], ans, n, m, siz, maxn, rt;
int s[N], top, k;
bool vis[N];
vector<pair<int, int>> G[N];
void getroot(int u, int fa)
{
	sz[u] = 1;
	int res = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		if (vis[G[u][i].first] || G[u][i].first == fa)
			continue;
		getroot(G[u][i].first, u);
		sz[u] += sz[G[u][i].first];
		res = max(res, sz[G[u][i].first]);
	}
	res = max(res, siz - sz[u]);
	if (res < maxn)
		maxn = res, rt = u;
}
void getdis(int u, int fa)
{
	s[++top] = dis[u];
	for (int i = 0; i < G[u].size(); ++i)
	{
		if (vis[G[u][i].first] || G[u][i].first == fa)
			continue;
		dis[G[u][i].first] = dis[u] + G[u][i].second;
		getdis(G[u][i].first, u);
	}
}
int solve(int u, int d)
{
	top = 0;
	dis[u] = d;
	getdis(u, 0);
	sort(s + 1, s + top + 1);
	int res = 0;
	int l = 1, r = top;
	while (l < r)
	{
		while (l < r && s[l] + s[r] > k)
			--r;
		if (l < r)
			res += r - l;
		++l;
	}
	return res;
}
void dfs(int u)
{
	vis[u] = 1;
	ans += solve(u, 0);
	for (int i = 0; i < G[u].size(); ++i)
	{
		if (vis[G[u][i].first])
			continue;
		ans -= solve(G[u][i].first, G[u][i].second);
		maxn = INF, rt = 0;
		siz = sz[G[u][i].first] > sz[u] ? n - sz[u] : sz[G[u][i].first];
		getroot(G[u][i].first, 0);
		dfs(rt);
	}
}
int main()
{
	while (scanf("%d%d", &n, &k) && n && k)
	{
		for (int i = 1; i <= n; ++i)
			G[i].clear();
		memset(vis, 0, sizeof(vis[0]) * (n + 1));
		ans = 0;
		int a, b, c;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
		}
		maxn = INF, rt = 0;
		siz = n;
		getroot(1, 0);
		dfs(rt);
		printf("%d\n", ans);
	}
	return 0;
}