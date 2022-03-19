#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 35;
//struct Trie
//{
int rnk[MAXN], id[MAXN], sz[MAXN];
int tot = 0, val[MAXN];
vector<int> G[MAXN];
void init1()
{
	rnk[0] = id[0] = tot = 0;
}
void CreateG(int n)
{
	for (int i = 1; i <= n; ++i)
		G[i].clear();
	int a;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &a);
		G[i + 1].push_back(a);
		G[a].push_back(i + 1);
	}
}
void dfs(int u, int f)
{
	id[u] = ++tot;
	rnk[tot] = u;
	sz[u] = 1;
	for (auto i : G[u])
		if (i != f)
			dfs(i, u), sz[u] += sz[i];
}
int tr[MAXN * MAXM][2], lat[MAXN * MAXM];
int cnt, root[MAXN];
void init2()
{
	cnt = 0;
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
	int c = val[rnk[i]] >> k & 1;
	if (x)
		tr[x][c ^ 1] = tr[f][c ^ 1];
	tr[x][c] = ++cnt;
	insert(i, k - 1, tr[x][c], tr[f][c]);
	lat[x] = max(lat[tr[x][0]], lat[tr[x][1]]);
}
int query(int now, int v, int k, int l)
{
	if (k < 0)
		return val[rnk[lat[now]]] ^ v;
	int c = v >> k & 1;
	if (lat[tr[now][c ^ 1]] >= l)
		return query(tr[now][c ^ 1], v, k - 1, l);
	else
		return query(tr[now][c], v, k - 1, l);
}
//};
//Trie tr;
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		init1();
		init2();
		CreateG(n);
		dfs(1, 0);
		for (int i = 1; i <= tot; ++i)
		{
			root[i] = ++cnt;
			insert(i, 31, root[i], root[i - 1]);
		}
		int u, x;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d", &u, &x);
			printf("%d\n", query(root[id[u] + sz[u] - 1], x, 31, id[u]));
		}
	}
	return 0;
}
