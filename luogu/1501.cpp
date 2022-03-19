#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int mod = 51061;
#define lc(x) son[x][0]
#define rc(x) son[x][1]
struct LCT
{
	int fa[MAXN], son[MAXN][2], sz[MAXN];
	ll s[MAXN], val[MAXN], atag[MAXN], mtag[MAXN];
	bool tag[MAXN];
	int getson(int x)
	{
		return rc(fa[x]) == x;
	}
	int notrt(int x)
	{
		return lc(fa[x]) == x || rc(fa[x]) == x;
	}
	void pushtag(int x)
	{
		swap(lc(x), rc(x));
		tag[x] ^= 1;
	}
	void pushup(int x)
	{
		s[x] = (s[lc(x)] + s[rc(x)] + val[x]) % mod;
		sz[x] = sz[lc(x)] + sz[rc(x)] + 1;
	}
	void pushadd(int x, ll c)
	{
		s[x] = (s[x] + (ll)c * sz[x]) % mod;
		val[x] = (val[x] + c) % mod;
		atag[x] = (atag[x] + c) % mod;
	}
	void pushmul(int x, ll c)
	{
		s[x] = s[x] * c % mod;
		val[x] = val[x] * c % mod;
		atag[x] = atag[x] * c % mod;
		mtag[x] = mtag[x] * c % mod;
	}
	void pushdown(int x)
	{
		if (mtag[x] != 1)
			pushmul(lc(x), mtag[x]), pushmul(rc(x), mtag[x]), mtag[x] = 1;
		if (atag[x])
			pushadd(lc(x), atag[x]), pushadd(rc(x), atag[x]), atag[x] = 0;
		if (tag[x])
			pushtag(lc(x)), pushtag(rc(x)), tag[x] = 0;
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
char op[2];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		tr.sz[i] = tr.val[i] = tr.mtag[i] = 1;
	int a, b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		tr.link(a, b);
	}
	int x, y, c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", op);
		if (op[0] == '+') 
		{
			scanf("%d%d%d", &x, &y, &c);
			tr.split(x, y);
			tr.pushadd(y, c);
		}
		else if (op[0] == '-')
		{
			scanf("%d%d%d%d", &a, &b, &x, &y);
			tr.cut(a, b);
			tr.link(x, y);
		}
		else if (op[0] == '*')
		{
			scanf("%d%d%d", &x, &y, &c);
			tr.split(x, y);
			tr.pushmul(y, c);
		}
		else if (op[0] == '/')
		{
			scanf("%d%d", &x, &y);
			tr.split(x, y);
			printf("%lld\n", tr.s[y] % mod);
		}
	}
	return 0;
}