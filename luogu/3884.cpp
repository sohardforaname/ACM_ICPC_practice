#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dep[N];
int fa[N];
int buc[N];
vector<int>G[N];
void dfs(int f, int u, int& maxn)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	maxn = max(dep[u], maxn);
	++buc[dep[u]];
	for (auto i : G[u])
		if (i != f)
			dfs(u, i, maxn);
}
int lca(int u, int v)
{
	bool tag = 0;
	if (dep[u] < dep[v])
		swap(u, v), tag = 1;
	int ust = 0, vst = 0;
	while (dep[u] > dep[v])
		++ust, u = fa[u];
	while (u != v)
	{
		u = fa[u];
		v = fa[v];
		++ust, ++vst;
	}
	if (tag)
		return vst * 2 + ust;
	else
		return ust * 2 + vst;
}
int main()
{
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int maxn = 0;
	dfs(0, 1, maxn);
	int u, v;
	scanf("%d%d", &u, &v);
	printf("%d\n%d\n%d\n", maxn, *max_element(buc + 1, buc + N + 1), lca(u, v));
	return 0;
}