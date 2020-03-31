#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<int>G[MAXN];
int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
int top[MAXN], rnk[MAXN], id[MAXN], val[MAXN];
int cnt;
void crtGrp(int n)
{
	int a;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &a);
		G[i + 1].push_back(a + 1);
		G[a + 1].push_back(i + 1);
	}
}
void dfs1(int u, int f)
{
	fa[u] = f;
	sz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	for (auto i : G[u])
	{
		if (i == f)
			continue;
		dfs1(i, u);
		sz[u] += sz[i];
		if (sz[i] > sz[son[u]])
			son[u] = i;
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++cnt;
	rnk[cnt] = u;
	if (!son[u])
		return;
	dfs2(son[u], t);
	for (auto i : G[u])
		if (i != fa[u] && i != son[u])
			dfs2(i, i);
}
#define ls (k<<1)
#define rs ((k<<1)+1)
int tl[MAXN << 2], tr[MAXN << 2];
int sum[MAXN << 2], lazy[MAXN << 2];
void up(int k)
{
	sum[k] = sum[ls] + sum[rs];
}
void down(int k)
{
	if (lazy[k] != -1)
	{
		lazy[ls] = lazy[k];
		lazy[rs] = lazy[k];
		sum[ls] = lazy[k] * (tr[ls] - tl[ls] + 1);
		sum[rs] = lazy[k] * (tr[rs] - tl[rs] + 1);
		lazy[k] = -1;
	}
}
void build(int l, int r, int k)
{
	tl[k] = l, tr[k] = r;
	lazy[k] = -1;
	if (l == r)
	{
		sum[k] = val[rnk[l]];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls);
	build(m + 1, r, rs);
	up(k);
}
void update(int l, int r, int k, int val)
{
	if (l <= tl[k] && r >= tr[k])
	{
		lazy[k] = val;
		sum[k] = (tr[k] - tl[k] + 1) * val;
		return;
	}
	down(k);
	int m = (tl[k] + tr[k]) >> 1;
	if (l <= m)
		update(l, r, ls, val);
	if (r > m)
		update(l, r, rs, val);
	up(k);
}
void update(int x, int y, int val)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		update(id[top[x]], id[x], 1, val);
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	update(id[x], id[y], 1, val);
}
int query(int l, int r, int k)
{
	if (l <= tl[k] && r >= tr[k])
		return sum[k];
	int ans = 0;
	down(k);
	int m = (tl[k] + tr[k]) >> 1;
	if (l <= m)
		ans += query(l, r, ls);
	if (r > m)
		ans += query(l, r, rs);
	return ans;
}
int query(int x, int y)
{
	int ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		ans += query(id[top[x]], id[x], 1);
		x = fa[top[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	ans += query(id[x], id[y], 1);
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	crtGrp(n);
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, cnt, 1);
	int m, a;
	scanf("%d", &m);
	char str[20];
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d", str, &a);
		a += 1;
		if (str[0] == 'i')
		{
			printf("%d\n", dep[a] - query(1, a));
			update(1, a, 1);
		}
		else if (str[0] == 'u')
		{
			printf("%d\n", query(id[a], id[a] + sz[a] - 1, 1));
			update(id[a], id[a] + sz[a] - 1, 1, 0);
		}
	}
	return 0;
}
