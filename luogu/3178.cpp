#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<int>G[MAXN];
int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
int top[MAXN], rnk[MAXN], id[MAXN], val[MAXN];
int cnt;
void init()
{
	fa[0] = dep[0] = sz[0] = son[0] = 0;
	top[0] = rnk[0] = id[0] = val[0] = 0;
	cnt = 0;
}
void crtGrp(int n)
{
	int a, b;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
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
long long sum[MAXN << 2], lazy[MAXN << 2];
void up(int k)
{
	sum[k] = sum[ls] + sum[rs];
}
void down(int k)
{
	lazy[ls] += lazy[k];
	lazy[rs] += lazy[k];
	sum[ls] += lazy[k] * (tr[ls] - tl[ls] + 1);
	sum[rs] += lazy[k] * (tr[rs] - tl[rs] + 1);
	lazy[k] = 0;
}
void build(int l, int r, int k)
{
	tl[k] = l, tr[k] = r;
	lazy[k] = 0;
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
		lazy[k] += val;
		sum[k] += (tr[k] - tl[k] + 1ll) * val;
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
void update(int pos, int val, int k)
{
	if (tl[k] == tr[k])
	{
		sum[k] += val;
		return;
	}
	down(k);
	int m = (tl[k] + tr[k]) >> 1;
	if (pos <= m)
		update(pos, val, ls);
	else if (pos > m)
		update(pos, val, rs);
	up(k);
}
long long query(int l, int r, int k)
{
	if (l <= tl[k] && r >= tr[k])
		return sum[k];
	long long ans = 0;
	down(k);
	int m = (tl[k] + tr[k]) >> 1;
	if (l <= m)
		ans += query(l, r, ls);
	if (r > m)
		ans += query(l, r, rs);
	return ans;
}
long long query(int x, int y)
{
	long long ans = 0;
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
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	crtGrp(n);
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, cnt, 1);
	int op, a, b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &op, &a);
		if (op == 1)
		{
			scanf("%d", &b);
			update(id[a], b, 1);
		}
		else if (op == 2)
		{
			scanf("%d", &b);
			update(id[a], id[a] + sz[a] - 1, 1, b);
		}
		else if (op == 3)
			printf("%lld\n", query(1, a));
	}
	return 0;
}
