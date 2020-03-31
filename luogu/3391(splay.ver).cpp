#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
struct Splay
{
	int fa[MAXN], son[MAXN][2], size[MAXN], val[MAXN];
	int tag[MAXN];
	int rt, sz;
	void init()
	{
		rt = sz = 0;
	}
	void pushup(int x)
	{
		if (x)
		{
			size[x] = 1;
			if (son[x][0])
				size[x] += size[son[x][0]];
			if (son[x][1])
				size[x] += size[son[x][1]];
		}
	}
	void pushdown(int x)
	{
		if (tag[x])
		{
			tag[son[x][0]] ^= 1;
			tag[son[x][1]] ^= 1;
			tag[x] = 0;
			swap(son[x][0], son[x][1]);
		}
	}
	int getson(int x)
	{
		return son[fa[x]][1] == x;
	}
	void con(int x, int y, int z)
	{
		if (x)
			fa[x] = y;
		if (y)
			son[y][z] = x;
	}
	void rotate(int x)
	{
		int fx = fa[x], ffx = fa[fx];
		int fs = getson(x), ffs = getson(fx);
		pushdown(fx), pushdown(x);
		con(son[x][fs ^ 1], fx, fs);
		con(fx, x, fs ^ 1);
		con(x, ffx, ffs);
		pushup(fx);
	}
	void splay(int x, int end)
	{
		end = fa[end];
		int f;
		pushdown(x);
		while (fa[x] != end)
		{
			f = fa[x];
			if (fa[f] != end)
				rotate(getson(f) == getson(x) ? f : x);
			rotate(x);
		}
		pushup(x);
		if (!end)
			rt = x;
	}
	int newnode(int x, int f)
	{
		int root = ++sz;
		fa[root] = f;
		son[root][0] = son[root][1] = 0;
		val[root] = x;
		size[root] = 1;
		tag[root] = 0;
		return root;
	}
	int build(int f, int l, int r)
	{
		if (l > r)
			return 0;
		int mid = (l + r) >> 1;
		int tmp = newnode(a[mid], f);
		son[tmp][0] = build(tmp, l, mid - 1);
		son[tmp][1] = build(tmp, mid + 1, r);
		pushup(tmp);
		return tmp;
	}
	int querynum(int x)
	{
		int now = rt;
		while (x)
		{
			pushdown(now);
			if (son[now][0] && x <= size[son[now][0]])
			{
				now = son[now][0];
				continue;
			}
			if (son[now][0])
				x -= size[son[now][0]];
			if (x == 1)
			{
				splay(now, rt);
				return now;
			}
			x -= 1;
			now = son[now][1];
		}
		return -1;
	}
	void reverse(int ql, int qr)
	{
		int l = querynum(ql), r = querynum(qr + 2);
		splay(l, rt), splay(r, son[l][1]);
		tag[son[r][0]] ^= 1;
	}
	void print(int rt,int n)
	{
		pushdown(rt);
		if (son[rt][0])
			print(son[rt][0], n);
		if (val[rt] && val[rt] <= n)
			printf("%d ", val[rt]);
		if (son[rt][1])
			print(son[rt][1], n);
	}
};
Splay sp;
int main()
{
	int n, m, l, r;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 2; ++i)
		a[i] = i - 1;
	sp.init();
	sp.rt = sp.build(0, 1, n + 2);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &l, &r);
		sp.reverse(l, r);
	}
	sp.print(sp.rt, n);
	putchar('\n');
	return 0;
}