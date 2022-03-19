#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct LCT
{
	int fa[MAXN], son[MAXN][2], val[MAXN], sz[MAXN];
	bool tag[MAXN];
	bool notrt(int x)
	{
		return son[fa[x]][0] == x || son[fa[x]][1] == x;
	}
	void pushtag(int x)
	{
		swap(son[x][0], son[x][1]);
		tag[x] ^= 1;
	}
	void pushdown(int x)
	{
		if (tag[x])
		{
			pushtag(son[x][0]);
			pushtag(son[x][1]);
			tag[x] = 0;
		}
	}
	void pushup(int x)
	{
		sz[x] = sz[son[x][0]] ^ sz[son[x][1]] ^ val[x];
	}
	int getson(int x)
	{
		return son[fa[x]][1] == x;
	}
	void rotate(int x)
	{
		int fx = fa[x], ffx = fa[fx];
		int fs = getson(x), ffs = getson(fx), xs = son[x][!fs];
		if (notrt(fx))
			son[ffx][ffs] = x;
		son[x][!fs] = fx, son[fx][fs] = xs;
		if (xs)
			fa[xs] = fx; 
		fa[fx] = x, fa[x] = ffx;
		pushup(fx);
	}
	void push(int x)
	{
		if (notrt(x))
			push(fa[x]);
		pushdown(x);
	}
	void splay(int x)
	{
		int fx, ffx;
		push(x);
		while (notrt(x))
		{
			fx = fa[x], ffx = fa[fx];
			if (notrt(fx))
				rotate((son[ffx][0] == fx) ^ (son[fx][0] == x) ? x : fx);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x)
	{
		for (int i = 0; x; x = fa[i])
		{
			splay(x);
			son[x][1] = i;
			pushup(x);
			i = x;
		}
	}
	void makeroot(int x)
	{
		access(x);
		splay(x);
		pushtag(x);
	}
	int findroot(int x)
	{
		access(x); 
		splay(x);
		while (son[x][0])
			pushdown(x), x = son[x][0];
		splay(x);
		return x;
	}
	void split(int x, int y)
	{
		makeroot(x);
		access(y);
		splay(y);
	}
	void link(int x, int y)
	{
		makeroot(x);
		if (findroot(y) != x)
			fa[x] = y;
	}
	void cut(int x, int y)
	{
		makeroot(x);
		if (findroot(y) == x && fa[y] == x && !son[y][0])
			fa[y] = son[x][1] = 0, pushup(x);
	}
};
LCT tr;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &tr.val[i]);
	int op, x, y;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%dd", &op, &x, &y);
		if (op == 0)
			tr.split(x, y), printf("%d\n", tr.sz[y]);
		else if (op == 1)
			tr.link(x, y);
		else if (op == 2)
			tr.cut(x, y);
		else if (op == 3)
			tr.splay(x), tr.val[x] = y;
	}
	return 0;
}