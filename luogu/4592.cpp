#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 32;
struct Trie
{
	vector<int>G[MAXN];
	int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
	int id[MAXN], top[MAXN], val[MAXN];
	int tot, rank[MAXN];
	void init1()
	{
		fa[0] = dep[0] = sz[0] = son[0] = 0;
		id[0] = top[0] = val[0] = tot = 0;
	}
	void CreateG(int n)
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
		dep[u] = dep[f] + 1;
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
		id[u] = ++tot;
		rank[tot] = u;
		if (!son[u])
			return;
		dfs2(son[u], t);
		for (auto i : G[u])
			if (i != son[u] && i != fa[u])
				dfs2(i, i);
	}
	//
	int tr[MAXN * MAXM][2], root[MAXN];
	int lat[MAXN * MAXM], cnt = 0;
	void init2()
	{
		root[0] = ++cnt;
		lat[0] = -1;
	}
	void insert(int i, int k, int x, int f)
	{
		if (k < 0)
		{
			lat[x] = i;
			return;
		}
		int c = val[rank[i]] >> k & 1;
		if (x)
			tr[x][c ^ 1] = tr[f][c ^ 1];
		tr[x][c] = ++cnt;
		insert(i, k - 1, tr[x][c], tr[f][c]);
		lat[x] = max(lat[tr[x][0]], lat[tr[x][1]]);
	}
	int query(int now, int v, int k, int l)
	{
		if (k < 0)
			return val[rank[lat[now]]] ^ v;
		int c = v >> k & 1;
		if (lat[tr[now][c ^ 1]] >= l)
			return query(tr[now][c ^ 1], v, k - 1, l);
		else
			return query(tr[now][c], v, k - 1, l);
	}
	int tr_query(int x, int y, int v)
	{
		int ans = 0;
		while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])
				swap(x, y);
			ans = max(ans, query(root[id[x]], v, 30, id[top[x]]));
			x = fa[top[x]];
		}
		if (id[x] > id[y])
			swap(x, y);
		return max(ans, query(root[id[y]], v, 30, id[x]));
	}
};
Trie tr;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	tr.init1();
	tr.CreateG(n);
	tr.dfs1(1, 0);
	tr.dfs2(1, 1);
	tr.init2();
	for (int i = 1; i <= tr.tot; ++i)
	{
		tr.root[i] = ++tr.cnt;
		tr.insert(i, 30, tr.root[i], tr.root[i - 1]);
	}
	int op;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", tr.query(tr.root[tr.id[x] + tr.sz[x] - 1], y, 30, tr.id[x]));
		}
		else if (op == 2)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			printf("%d\n", tr.tr_query(x, y, z));
		}
	}
	return 0;
}