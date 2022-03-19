#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>G[N];
int dep[N], f[N][20];
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (auto i : G[u])
		if (!dep[i])
			dfs(i, u);
}
void getfa(int n)
{
	for (int i = 1; i < 20; ++i)
		for (int j = 1; j <= n; ++j)
			f[j][i] = f[f[j][i - 1]][i - 1];
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);
	for (int i = 0; (1 << i) <= (dep[a] - dep[b]); ++i)
		if ((dep[a] - dep[b]) & (1 << i))
			a = f[a][i];
	if (a == b)
		return a;
	for (int i = 19; ~i; --i)
		if (f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	return f[a][0];
}
int getdis(int u, int v)
{
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int main()
{
	int n, q, u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	getfa(n);
	int a, b, k;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d%d%d%d", &u, &v, &a, &b, &k);
		int disa = getdis(a, b), disb = getdis(a, u) + getdis(b, v) + 1, disc = getdis(a, v) + getdis(b, u) + 1;
		if ((k >= disa && (k - disa) % 2 == 0) || (k >= disb && (k - disb) % 2 == 0) || (k >= disc && (k - disc) % 2 == 0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}