#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct LCT
{
	int fa[N], son[N][2];
	bool tag[N];
	bool notrt(int x)
	{
		return son[fa[x]][0] == x || son[fa[x]][1] == x;
	}
	bool getson(int x)
	{
		return son[fa[x]][1] == x;
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
	void push(int x)
	{
		if (notrt(x))
			push(fa[x]);
		pushdown(x);
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
	}
	void splay(int x)
	{
		int fx, ffx;
		push(x);
		while (notrt(x))
		{
			fx = fa[x], ffx = fa[fx];
			if (notrt(fx))
				rotate(getson(fx) == getson(ffx) ? fx : x);
			rotate(x);
		}
	}
	void access(int x)
	{
		for (int i = 0; x; x = fa[i])
		{
			splay(x);
			son[x][1] = i;
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
			fa[y] = son[x][1] = 0;
	}
};
char op[10];
LCT tr;
int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d%d", op, &a, &b);
		if (op[0] == 'C')
			tr.link(a, b);
		else if (op[0] == 'D')
			tr.cut(a, b);
		else if (op[0] == 'Q')
		{
			if (tr.findroot(a) != tr.findroot(b))
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}