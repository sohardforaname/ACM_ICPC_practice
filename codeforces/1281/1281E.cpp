#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
struct edge
{
	int to, w;
	edge() {}
	edge(int _to, int _w) :to(_to), w(_w) {}
};
vector<edge>G[MAXN];
int sz[MAXN], dep[MAXN];
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	sz[u] = 1;
	for (auto i : G[u])
		if (!dep[i.to])
		{
			dfs(i.to, u);
			sz[u] += sz[i.to];
		}
}
void solve()
{
	int n;
	scanf("%d", &n);
	n <<= 1;
	int a, b, c;
	memset(sz, 0, sizeof(sz[0]) * (n + 1));
	memset(dep, 0, sizeof(dep[0]) * (n + 1));
	for (int i = 1; i <= n; ++i)
		G[i].clear();
	for (int i = 1; i <= n - 1; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back(edge(b, c));
		G[b].push_back(edge(a, c));
	}
	dfs(1, 0);
	ll maxn = 0, minn = 0;
	for (int i = 1; i <= n; ++i)
		for (auto j : G[i])
		{
			int a = i, b = j.to;
			if (dep[a] > dep[b])
				swap(a, b);
			maxn += (ll)min(sz[b], n - sz[b]) * j.w;
			if (sz[b] % 2 || (n - sz[b]) % 2)
				minn += j.w;
		}
	printf("%lld %lld\n", minn / 2, maxn / 2);
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}