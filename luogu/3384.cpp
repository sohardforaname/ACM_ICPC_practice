#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int mod;
struct treediv
{
	vector<int> G[MAXN];
	int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
	int id[MAXN], top[MAXN], val[MAXN];
	int cnt, rnk[MAXN];
	void init()
	{
		fa[0] = dep[0] = sz[0] = son[0] = id[0] = top[0] = val[0] = 0;
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
		dep[u] = dep[fa[u]] + 1;
		sz[u] = 1;
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
#define ls (k << 1)
#define rs ((k << 1) + 1)
	treediv td;
	struct node
	{
		int l, r, sum, lazy;
	};
	node tr[MAXN << 2];
	void init(int n, int rt)
	{
		td.init();
		td.crtGrp(n);
		td.dfs1(rt, 0);
		td.dfs2(rt, rt);
	}
	void up(int k)
	{
		tr[k].sum = (tr[ls].sum + tr[rs].sum) % mod;
	}
	void down(int k)
	{
		tr[ls].lazy = (tr[ls].lazy + tr[k].lazy) % mod;
		tr[rs].lazy = (tr[rs].lazy + tr[k].lazy) % mod;
		tr[ls].sum = (tr[ls].sum % mod + tr[k].lazy * (tr[ls].r - tr[ls].l + 1) % mod) % mod;
		tr[rs].sum = (tr[rs].sum % mod + tr[k].lazy * (tr[rs].r - tr[rs].l + 1) % mod) % mod;
		tr[k].lazy = 0;
	}
	void build(int l, int r, int k)
	{
		tr[k].lazy = 0;
		tr[k].l = l, tr[k].r = r;
		if (l == r)
		{
			tr[k].sum = td.val[td.rnk[l]];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		up(k);
	}
	void update(int l, int r, int k, int val)
	{
		if (l <= tr[k].l && r >= tr[k].r)
		{
			tr[k].lazy = (tr[k].lazy + val) % mod;
			tr[k].sum = (tr[k].sum % mod + val * (tr[k].r - tr[k].l + 1) % mod) % mod;
			return;
		}
		down(k);
		int m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			update(l, r, ls, val);
		if (r > m)
			update(l, r, rs, val);
		up(k);
	}
	int query(int l, int r, int k)
	{
		if (l <= tr[k].l && r >= tr[k].r)
			return tr[k].sum;
		down(k);
		int ans = 0, m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			(ans += query(l, r, ls)) %= mod;
		if (r > m)
			(ans += query(l, r, rs)) %= mod;
		return ans;
	}
	int tr_query(int x, int y)
	{
		int ans = 0;
		while (td.top[x] != td.top[y])
		{
			if (td.dep[td.top[x]] < td.dep[td.top[y]])
				swap(x, y);
			(ans += query(td.id[td.top[x]], td.id[x], 1)) %= mod;
			x = td.fa[td.top[x]];
		}
		if (td.id[x] > td.id[y])
			swap(x, y);
		return (ans + query(td.id[x], td.id[y], 1)) % mod;
	}
	void tr_upd(int x, int y, int val)
	{
		while (td.top[x] != td.top[y])
		{
			if (td.dep[td.top[x]] < td.dep[td.top[y]])
				swap(x, y);
			update(td.id[td.top[x]], td.id[x], 1, val);
			x = td.fa[td.top[x]];
		}
		if (td.id[x] > td.id[y])
			swap(x, y);
		update(td.id[x], td.id[y], 1, val);
	}
};
segtree tr;
int main()
{
	int n, m, rt;
	scanf("%d%d%d%d", &n, &m, &rt, &mod);
	tr.init(n, rt);
	tr.build(1, tr.td.cnt, 1);
	int op, x, y, c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d%d%d", &x, &y, &c);
			tr.tr_upd(x, y, c);
		}
		else if (op == 2)
		{
			scanf("%d%d", &x, &y);
			printf("%d\n", tr.tr_query(x, y));
		}
		else if (op == 3)
		{
			scanf("%d%d", &x, &c);
			tr.update(tr.td.id[x], tr.td.id[x] + tr.td.sz[x] - 1, 1, c);
		}
		else if (op == 4)
		{
			scanf("%d", &x);
			printf("%d\n", tr.query(tr.td.id[x], tr.td.id[x] + tr.td.sz[x] - 1, 1));
		}
	}
	return 0;
}
