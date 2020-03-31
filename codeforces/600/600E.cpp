#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
vector<int> G[MAXN];
int col[MAXN], son[MAXN], sz[MAXN];
bool vis[MAXN];
ll tot[MAXN], ans[MAXN];
ll maxn, c;
void dfs1(int u, int fa)
{
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
void update(int u, int fa, int p)
{
	tot[col[u]] += p;
	if (p > 0 && maxn == tot[col[u]])
		c += col[u];
	else if (p > 0 && maxn < tot[col[u]])
		c = col[u], maxn = tot[col[u]];
	for (auto i : G[u])
		if (i != fa && !vis[i])
			update(i, u, p);
}
void dfs2(int u, int fa, int op)
{
	for (auto i : G[u])
		if (i != son[u] && i != fa)
			dfs2(i, u, 0); //tot: n
	if (son[u])
		dfs2(son[u], u, 1), vis[son[u]] = 1; //tot: n
	update(u, fa, 1), ans[u] = c;			 //tot: nlogn
	if (son[u])
		vis[son[u]] = 0;
	if (!op)
		update(u, fa, -1), maxn = c = 0; //tot: nlogn
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &col[i]);
	int a, b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs1(1, 0);	   //tot: n
	dfs2(1, 0, 0); //tot: n+2nlogn
	for (int i = 1; i <= n; ++i)
		printf("%lld%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}