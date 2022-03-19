#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int sz[N], dis[N], n, maxn, rt, siz;
int ans;
bool vis[N];
vector<pair<int, int> >G[N];
int sum[3];
void getroot(int u, int fa)
{
	sz[u] = 1;
	int res = 0;
	for (auto i : G[u])
	{
		if (vis[i.first] || i.first == fa)
			continue;
		getroot(i.first, u);
		sz[u] += sz[i.first];
		res = max(res, sz[i.first]);
	}
	res = max(res, siz - sz[u]);
	if (res < maxn)
		maxn = res, rt = u;
}
void getdis(int u, int fa)
{
	++sum[dis[u] % 3];
	for (auto i : G[u])
	{
		if (vis[i.first] || i.first == fa)
			continue;
		dis[i.first] = dis[u] + i.second;
		getdis(i.first, u);
	}
}
int solve(int u, int d)
{
	memset(sum, 0, sizeof(sum));
	dis[u] = d;
	getdis(u, 0);
	return sum[0] * sum[0] + sum[1] * sum[2] * 2;
}
void dfs(int u)
{
	vis[u] = 1;
	ans += solve(u, 0);
	for (auto i : G[u])
	{
		if (vis[i.first])
			continue;
		ans -= solve(i.first, i.second);
		maxn = 0x3f3f3f3f, rt = 0;
		siz = sz[i.first] > sz[u] ? n - sz[u] : sz[i.first];
		getroot(i.first, 0);
		dfs(rt);
	}
}
int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}
	maxn = 0x3f3f3f3f;
	rt = 0;
	siz = n;
	getroot(1, 0);
	dfs(rt);
	int tot = n * n, div = gcd(ans, tot);
	printf("%d/%d\n", ans / div, tot / div);
	return 0;
}