#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5e3 + 5;
typedef long long ll;
#define lc(x) son[x][0]
#define rc(x) son[x][1]
struct LCT
{
	int fa[MAXN], son[MAXN][2], maxn[MAXN], maxid[MAXN];
	int val[MAXN];
	bool tag[MAXN];
	bool notrt(int x)
	{
		return lc(fa[x]) == x || rc(fa[x]) == x;
	}
	bool getson(int x)
	{
		return rc(fa[x]) == x;
	}
	void pushup(int x)
	{
		maxn[x] = val[x], maxid[x] = x;
		if (maxn[lc(x)] > maxn[x])
			maxn[x] = maxn[lc(x)], maxid[x] = maxid[lc(x)];
		if (maxn[rc(x)] > maxn[x])
			maxn[x] = maxn[rc(x)], maxid[x] = maxid[rc(x)];
	}
	void pushtag(int x)
	{
		swap(lc(x), rc(x));
		tag[x] ^= 1;
	}
	void pushdown(int x)
	{
		if (tag[x])
		{
			pushtag(lc(x));
			pushtag(rc(x));
			tag[x] = 0;
		}
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
	bool check(int x, int y)
	{
		makeroot(x);
		return findroot(y) == x;
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
	ll ans = 0;
	int x, y, z;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		tr.val[i + n] = z;
		if (!tr.check(x, y))
			tr.link(x, i + n), tr.link(i + n, y), ans += z;
		else
		{
			tr.split(x, y);
			int maxid = tr.maxid[y], maxn = tr.maxn[y];
			if (maxn > z)
			{
				ans += z - maxn;
				tr.splay(maxid);
				tr.fa[tr.son[maxid][0]] = tr.fa[tr.son[maxid][1]] = 0;
				tr.link(x, i + n), tr.link(i + n, y);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}