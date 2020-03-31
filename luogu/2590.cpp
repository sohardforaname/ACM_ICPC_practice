#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 5;
const int INF = 0x3f3f3f3f;
struct treediv
{
	vector<int>G[MAXN];
	int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
	int top[MAXN], id[MAXN], rnk[MAXN], val[MAXN], cnt;
	void init()
	{
		fa[0] = dep[0] = sz[0] = son[0] = 0;
		top[0] = id[0] = rnk[0] = cnt = 0;
	}
	int crtGrp(int n)
	{
		int a, b;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for (int i = 1; i <= n; ++i)
			scanf("%d", &val[i]);
		return 1;
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
			if (i != son[u] && i != fa[u])
				dfs2(i, i);
	}
};
struct segtree
{
#define ls (k<<1)
#define rs ((k<<1)+1)
	treediv td;
	int trl[MAXN << 2], trr[MAXN << 2], sum[MAXN << 2], maxn[MAXN << 2];
	void init(int n)
	{
		td.init();
		memset(maxn, -INF, sizeof(maxn));
		int rt = td.crtGrp(n);
		td.dfs1(rt, 0);
		td.dfs2(rt, rt);
		build(1, td.cnt, 1);
	}
	void up(int k)
	{
		sum[k] = sum[ls] + sum[rs];
		maxn[k] = max(maxn[ls], maxn[rs]);
	}
	void build(int l, int r, int k)
	{
		trl[k] = l, trr[k] = r;
		sum[k] = maxn[k] = 0;
		if (l == r)
		{
			sum[k] = maxn[k] = td.val[td.rnk[l]];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		up(k);
	}
	void update(int pos, int val, int k)
	{
		if (trl[k] == trr[k])
		{
			sum[k] = maxn[k] = val;
			return;
		}
		int m = (trl[k] + trr[k]) >> 1;
		if (pos <= m)
			update(pos, val, ls);
		else
			update(pos, val, rs);
		up(k);
	}
	int query_max(int l, int r, int k)
	{
		if (l <= trl[k] && r >= trr[k])
			return maxn[k];
		int maxx = -INF, m = (trl[k] + trr[k]) >> 1;
		if (l <= m)
			maxx = max(maxx, query_max(l, r, ls));
		if (r > m)
			maxx = max(maxx, query_max(l, r, rs));
		return maxx;
	}
	int query_sum(int l, int r, int k)
	{
		if (l <= trl[k] && r >= trr[k])
			return sum[k];
		int ans = 0, m = (trl[k] + trr[k]) >> 1;
		if (l <= m)
			ans += query_sum(l, r, ls);
		if (r > m)
			ans += query_sum(l, r, rs);
		return ans;
	}
	int tr_query_max(int x, int y)
	{
		int maxx = -INF;
		while (td.top[x] != td.top[y])
		{
			if (td.dep[td.top[x]] < td.dep[td.top[y]])
				swap(x, y);
			maxx = max(maxx, query_max(td.id[td.top[x]], td.id[x], 1));
			x = td.fa[td.top[x]];
		}
		if (td.id[x] > td.id[y])
			swap(x, y);
		maxx = max(maxx, query_max(td.id[x], td.id[y], 1));
		return maxx;
	}
	int tr_query_sum(int x, int y)
	{
		int ans = 0;
		while (td.top[x] != td.top[y])
		{
			if (td.dep[td.top[x]] < td.dep[td.top[y]])
				swap(x, y);
			ans += query_sum(td.id[td.top[x]], td.id[x], 1);
			x = td.fa[td.top[x]];
		}
		if (td.id[x] > td.id[y])
			swap(x, y);
		ans += query_sum(td.id[x], td.id[y], 1);
		return ans;
	}
};
segtree tr;
int main()
{
	int n, m;
	scanf("%d", &n);
	tr.init(n);
	scanf("%d", &m);
	char str[10];
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d%d", str, &a, &b);
		if (str[1] == 'H')
			tr.update(tr.td.id[a], b, 1);
		else if (str[1] == 'M')
			printf("%d\n", tr.tr_query_max(a, b));
		else if (str[1] == 'S')
			printf("%d\n", tr.tr_query_sum(a, b));
	}
	return 0;
}
