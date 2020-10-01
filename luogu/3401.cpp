#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
struct node
{
	int to, w;
	node() {}
	node(int _to, int _w) : to(_to), w(_w) {}
};
vector<node> G[N];
struct treediv
{
	int fa[N], dep[N], sz[N], son[N];
	int top[N], rnk[N], id[N], val[N], sum[N];
	int cnt = 0;
	void dfs1(int u, int f, int v)
	{
		fa[u] = f;
		dep[u] = dep[f] + 1;
		sz[u] = 1;
		val[u] = v;
		sum[u] = sum[f] ^ v;
		for (auto i : G[u])
		{
			if (i.to == f)
				continue;
			dfs1(i.to, u, i.w);
			sz[u] += sz[i.to];
			if (sz[i.to] > sz[son[u]])
				son[u] = i.to;
		}
	}
	void dfs2(int t, int u)
	{
		top[u] = t;
		id[u] = ++cnt;
		rnk[cnt] = u;
		if (!son[u])
			return;
		dfs2(t, son[u]);
		for (auto i : G[u])
			if (i.to != son[u] && i.to != fa[u])
				dfs2(i.to, i.to);
	}
};
treediv t;
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	struct node
	{
		int l, r, val;
		bool lazy;
	};
	node tr[N << 2];
	void pushup(int k)
	{
		tr[k].val = tr[ls].val + tr[rs].val;
	}
	void pushdown(int k)
	{
		if (tr[k].lazy)
		{
			tr[ls].lazy ^= tr[k].lazy;
			tr[rs].lazy ^= tr[k].lazy;
			tr[ls].val = tr[ls].r - tr[ls].l + 1 - tr[ls].val;
			tr[rs].val = tr[rs].r - tr[rs].l + 1 - tr[rs].val;
			tr[k].lazy = 0;
		}
	}
	void build(int l, int r, int k, int id)
	{
		tr[k].l = l, tr[k].r = r;
		tr[k].lazy = 0;
		if (l == r)
		{
			tr[k].val = (t.sum[t.rnk[l]] >> id) & 1;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls, id);
		build(m + 1, r, rs, id);
		pushup(k);
	}
	void update(int l, int r, int k, int v, int id)
	{
		if (l <= tr[k].l && r >= tr[k].r)
		{
			if ((v >> id) & 1)
			{
				tr[k].val = tr[k].r - tr[k].l + 1 - tr[k].val;
				tr[k].lazy ^= 1;
			}
			return;
		}
		pushdown(k);
		int m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			update(l, r, ls, v, id);
		if (r > m)
			update(l, r, rs, v, id);
		pushup(k);
	}
	int query(int l, int r, int k)
	{
		if (l <= tr[k].l && r >= tr[k].r)
			return tr[k].val;
		pushdown(k);
		int ans = 0, m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			ans += query(l, r, ls);
		if (r > m)
			ans += query(l, r, rs);
		return ans;
	}
};
segtree tr[10];
long long query(int u, int v, int k)
{
	long long ans = 0, num = 0;
	while (t.top[u] != t.top[v])
	{
		if (t.dep[t.top[u]] < t.dep[t.top[v]])
			swap(u, v);
		num += tr[k].query(t.id[t.top[u]], t.id[u], 1);
		ans += t.id[u] - t.id[t.top[u]] + 1;
		u = t.fa[t.top[u]];
	}
	if (t.id[u] > t.id[v])
		swap(u, v);
	num += tr[k].query(t.id[u], t.id[v], 1);
	ans += t.id[v] - t.id[u] + 1;
	return (ans - num) * num;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b, c;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back(node(b, c));
		G[b].push_back(node(a, c));
	}
	t.dfs1(1, 0, 0);
	t.dfs2(1, 1);
	for (int i = 0; i < 10; ++i)
		tr[i].build(1, t.cnt, 1, i);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d%d", &b, &c);
			long long ans = 0;
			for (int i = 0; i < 10; ++i)
				ans += query(b, c, i) * (1 << i);
			printf("%lld\n", ans);
		}
		else
		{
			scanf("%d%d%d", &a, &b, &c);
			if (t.dep[a] < t.dep[b])
				swap(a, b);
			for (int i = 0; i < 10; ++i)
				tr[i].update(t.id[a], t.id[a] + t.sz[a] - 1, 1, t.val[a], i);
			for (int i = 0; i < 10; ++i)
				tr[i].update(t.id[a], t.id[a] + t.sz[a] - 1, 1, c, i);
			t.val[a] = c;
		}
	}
	return 0;
}