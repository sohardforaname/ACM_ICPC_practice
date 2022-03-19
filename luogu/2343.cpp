#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Splay
{
	int fa[MAXN], val[MAXN], son[MAXN][2], size[MAXN], num[MAXN];
	int sz, rt;
	void init()
	{
		rt = sz = 0;
	}
	bool getson(int x)
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
	void up(int x)
	{
		if (x)
		{
			size[x] = num[x];
			if (son[x][0])
				size[x] += size[son[x][0]];
			if (son[x][1])
				size[x] += size[son[x][1]];
		}
	}
	void rotate(int x)
	{
		int fx = fa[x], ffx = fa[fx];
		int fs = getson(x), ffs = getson(fx);
		con(son[x][fs ^ 1], fx, fs);
		con(fx, x, fs ^ 1);
		con(x, ffx, ffs);
		up(fx), up(x);
	}
	void splay(int x, int end)
	{
		end = fa[end];
		int f;
		while (fa[x] != end)
		{
			f = fa[x];
			if (fa[f] != end)
				rotate(getson(x) == getson(f) ? f : x);
			rotate(x);
		}
		if (!end)
			rt = x;
	}
	int newnode(int x, int f)
	{
		int root = ++sz;
		fa[root] = f;
		son[f][x > val[f]] = root;
		son[root][0] = son[root][1] = 0;
		size[root] = num[root] = 1;
		val[root] = x;
		return root;
	}
	void insert(int x)
	{
		if (!rt)
		{
			rt = newnode(x, 0);
			return;
		}
		int now = rt, f = 0;
		while (1)
		{
			if (x == val[now])
			{
				++num[now];
				up(now), up(f);
				splay(now, rt);
				return;
			}
			f = now, now = son[now][x > val[now]];
			if (!now)
			{
				int tmp = newnode(x, f);
				up(f);
				splay(tmp, rt);
				return;
			}
		}
	}
	int querynum(int rnk)
	{
		int now = rt;
		while (1)
		{
			if (son[now][1] && rnk <= size[son[now][1]])
			{
				now = son[now][1];
				continue;
			}
			if (son[now][1])
				rnk -= size[son[now][1]];
			if (rnk <= num[now])
			{
				splay(now, rt);
				return now;
			}
			rnk -= num[now];
			now = son[now][0];
		}
	}
};
Splay sp;

const int MAXBUF = 1 << 20;
char buf[1 << 20], * fh = NULL, * ft = NULL;
inline char gc()
{
	if (fh == ft)
	{
		int l = fread(buf, 1, MAXBUF, stdin);
		ft = (fh = buf) + l;
	}
	return *fh++;
}

inline int read()
{
	int x = 0;
	char c = gc();
	for (; c < '0' || c > '9'; c = gc())
		;
	for (; c >= '0' && c <= '9'; c = gc())
		x = (x << 3) + (x << 1) + c - '0';
	return x;
}
inline void _write(long long x)
{
	if (x > 9)
		_write(x / 10);
	putchar(x % 10 + '0');
}
inline void write(long long x)
{
	_write(x);
	putchar('\n');
}


int main()
{
	sp.init();
	int n, m, a, op;
	//scanf("%d%d", &n, &m);
	n = read(), m = read();
	for (int i = 0; i < n; ++i)
	{
		//scanf("%d", &a);
		a = read();
		sp.insert(a);
	}
	for (int i = 0; i < m; ++i)
	{
		//scanf("%d%d", &op, &a);
		op = read(), a = read();
		if (op == 1)
			printf("%d\n", sp.val[sp.querynum(a)]);
		else if (op == 2)
			sp.insert(a);
	}
	return 0;
}
