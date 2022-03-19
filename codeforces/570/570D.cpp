#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
vector<int> G[MAXN];
struct Q
{
	int pos, dep;
	Q(int _pos, int _dep) : pos(_pos), dep(_dep) {}
};
vector<Q> q[MAXN];
bool ans[MAXN];
int dep[MAXN], val[MAXN], sz[MAXN];
int tot[MAXN], son[MAXN];
bool vis[MAXN];
void dfs1(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	sz[u] = 1;
	for (auto i : G[u])
		if (i != fa)
		{
			dfs1(i, u);
			sz[u] += sz[i];
			if (sz[i] > sz[son[u]])
				son[u] = i;
		}
}
bool get1(int val)
{
	int rt = 0;
	while (val)
		rt += val % 2, val >>= 1;
	return rt < 2;
}
void update(int u, int fa)
{
	tot[dep[u]] ^= val[u];
	for (auto i : G[u])
		if (i != fa && !vis[i])
			update(i, u);
}
void del(int u, int fa)
{
	tot[dep[u]] = 0;
	for (auto i : G[u])
		if (i != fa && !vis[i])
			del(i, u);
}
void dfs2(int u, int fa, int op)
{
	for (auto i : G[u])
		if (i != fa && i != son[u])
			dfs2(i, u, 0);
	if (son[u])
		dfs2(son[u], u, 1), vis[son[u]] = 1;
	update(u, fa);
	for (int i = 0; i < q[u].size(); ++i)
		ans[q[u][i].pos] = get1(tot[q[u][i].dep]);
	if (son[u])
		vis[son[u]] = 0;
	if (!op)
		del(u, fa);
}
char str[MAXN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &a);
		G[i + 1].push_back(a);
		G[a].push_back(i + 1);
	}
	scanf("%s", str + 1);
	for (int i = 1; i <= n; ++i)
		val[i] = 1 << (str[i] - 'a');
	int x, y;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &x, &y);
		q[x].push_back(Q(i, y));
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= m; ++i)
		printf(ans[i] ? "Yes\n" : "No\n");
	return 0;
}