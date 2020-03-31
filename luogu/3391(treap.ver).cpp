#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Treap
{
	int val[MAXN], son[MAXN][2], rnk[MAXN], size[MAXN];
	bool tag[MAXN];
	int sz;
	void init()
	{
		sz = 0;
	}
	void pushup(int x)
	{
		size[x] = size[son[x][0]] + size[son[x][1]] + 1;
	}
	void pushdown(int x)
	{
		if (tag[x])
		{
			tag[x] = 0;
			tag[son[x][0]] ^= 1;
			tag[son[x][1]] ^= 1;
			swap(son[x][0], son[x][1]);
		}
	}
	int _rand()
	{
		static int seed = 12345;
		return seed = int(seed * 482711ll % 2147483647);
	}
	void merge(int& rt, int a, int b)
	{
		if (!a || !b)
		{
			rt = a + b;
			return;
		}
		if (rnk[a] < rnk[b])
		{
			pushdown(a), rt = a;
			merge(son[rt][1], son[a][1], b);
		}
		else
		{
			pushdown(b), rt = b;
			merge(son[rt][0], a, son[b][0]);
		}
		pushup(rt);
	}
	void split_sz(int rt, int& a, int& b, int s)
	{
		if (rt == 0)
		{
			a = b = 0;
			return;
		}
		pushdown(rt);
		if (size[son[rt][0]] < s)
		{
			a = rt;
			split_sz(son[rt][1], son[a][1], b, s - size[son[a][0]] - 1);
		}
		else
		{
			b = rt;
			split_sz(son[rt][0], a, son[b][0], s);
		}
		pushup(rt);
	}
	void split_v(int rt, int& a, int& b, int v)
	{
		if (rt == 0)
		{
			a = b = 0;
			return;
		}
		pushdown(rt);
		if (val[a] <= v)
			a = rt, split_v(son[rt][1], son[a][1], b, v);
		else
			b = rt, split_v(son[rt][0], a, son[b][0], v);
		pushup(rt);
	}
	int newnode(int x)
	{
		int rt = ++sz;
		val[rt] = x;
		rnk[rt] = _rand();
		son[rt][0] = son[rt][1] = 0;
		size[rt] = 1;
		tag[rt] = 0;
		return rt;
	}
	void insert(int& rt, int v)
	{
		int x = 0, y = 0, n = newnode(v);
		split_v(rt, x, y, v);
		merge(x, x, n);
		merge(rt, x, y);
	}
	void rerverse(int& rt, int l, int r)
	{
		int x = 0, y = 0, z = 0;
		split_sz(rt, x, y, r);
		split_sz(x, x, z, l - 1);
		tag[z] ^= 1;
		merge(x, x, z);
		merge(rt, x, y);
	}
	void print(int rt)
	{
		pushdown(rt);
		if (son[rt][0])
			print(son[rt][0]);
		printf("%d ", val[rt]);
		if (son[rt][1])
			print(son[rt][1]);
	}
};
Treap tr;
int p = 0;
int main()
{
	tr.init();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		tr.insert(p, i);
	int l, r;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &l, &r);
		tr.rerverse(p, l, r);
	}
	tr.print(p);
	putchar('\n');
	return 0;
}
