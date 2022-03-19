#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int sz[N], dis[N];
int n, maxn, siz, rt, k;
int s[N], top;
unordered_map<int, int> mp;
bool vis[N];
vector<int> G[N];
long long ans;
void getroot(int u, int fa)
{
	sz[u] = 1;
	int res = 0;
	for (auto i : G[u])
	{
		if (vis[i] || i == fa)
			continue;
		getroot(i, u);
		sz[u] += sz[i];
		res = max(res, sz[i]);
	}
	res = max(res, siz - sz[u]);
	if (res < maxn)
		maxn = res, rt = u;
}
void getdis(int u, int fa)
{
	++mp[dis[u]];
	s[++top] = dis[u];
	for (auto i : G[u])
	{
		if (vis[i] || i == fa)
			continue;
		dis[i] = dis[u] + 1;
		getdis(i, u);
	}
}
long long solve(int u, int d)
{
	top = 0;
	mp.clear();
	dis[u] = d;
	getdis(u, 0);
	int res = 0;
	for (int i = 1; i <= top; ++i)
		if (s[i] <= k)
		{
			if (s[i] * 2 == k)
				res += mp[s[i]] * (mp[s[i]] - 1ll) / 2;
			else
				res += 1ll * mp[s[i]] * mp[k - s[i]];
			mp[s[i]] = mp[k - s[i]] = 0;
		}
	return res;
}
void dfs(int u)
{
	vis[u] = 1;
	ans += solve(u, 0);
	for (auto i : G[u])
	{
		if (vis[i])
			continue;
		ans -= solve(i, 1);
		maxn = 0x3f3f3f3f, rt = 0;
		siz = sz[i] > sz[u] ? n - sz[u] : sz[i];
		getroot(i, 0);
		dfs(rt);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	maxn = 0x3f3f3f3f, rt = 0;
	siz = n;
	getroot(1, 0);
	dfs(rt);
	printf("%lld\n", ans);
	return 0;
}