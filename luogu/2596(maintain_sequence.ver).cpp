#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
int hs[MAXN], a[MAXN];
struct Splay
{
	int fa[MAXN], son[MAXN][2], size[MAXN], val[MAXN];
	int sz, rt;
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
				size[x] += size[son[x][0]], hs[val[son[x][0]]] = son[x][0];
			if (son[x][1])
				size[x] += size[son[x][1]], hs[val[son[x][1]]] = son[x][1];
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
		con(son[x][fs ^ 1], fx, fs);
		con(fx, x, fs ^ 1);
		con(x, ffx, ffs);
		pushup(fx), pushup(x);
	}
	void splay(int x, int end)
	{
		end = fa[end];
		int f;
		while (fa[x] != end)
		{
			f = fa[x];
			if (fa[f] != end)
				rotate(getson(f) == getson(x) ? f : x);
			rotate(x);
		}
		if (!end)
			rt = x;
	}
	int newnode(int x,int f)
	{
		int root = ++sz;
		fa[root] = f;
		son[root][0] = son[root][1] = 0;
		val[root] = x;
		size[root] = 1;
		return root;
	}
	int build(int f, int l, int r)
	{
		if (l > r)
			return 0;
		int m = (l + r) >> 1;
		int tmp = newnode(a[m], f);
		son[tmp][0] = build(tmp, l, m - 1);
		son[tmp][1] = build(tmp, m + 1, r);
		hs[a[m]] = tmp;
		pushup(tmp);
		return tmp;
	}
	int pre_nxt(int m)
	{
		int now = son[rt][m];
		while (son[now][m ^ 1])
			now = son[now][m ^ 1];
		return now;
	}
	int minmax(int m)
	{
		int now = rt;
		while (son[now][m])
			now = son[now][m];
		return now;
	}
	//work
	void Top_Bot(int id, int m)
	{
		int pos = hs[id];
		splay(pos, rt);
		if (!son[pos][m])
			return;
		if (!son[pos][m ^ 1])
			son[pos][m ^ 1] = son[pos][m], son[pos][m] = 0;
		else
		{
			int tmp = (!m) ? pre_nxt(1) : pre_nxt(0);
			fa[son[rt][m]] = tmp;
			son[tmp][m] = son[rt][m];
			son[rt][m] = 0;
			splay(tmp, rt);
		}
	}
	void insert(int id, int m)
	{
		if (m)
		{
			int pos = hs[id];
			splay(pos, rt);
			int t = m == 1 ? pre_nxt(1) : pre_nxt(0);
			int v1 = val[t], p2 = hs[v1];
			swap(val[pos], val[t]);
			swap(hs[id], hs[v1]);
		}
	}
	int querynum(int x,int rnk)
	{
		int now = x;
		while (1)
		{
			if (!now)
				return 0;
			if (son[now][0] && rnk <= size[son[now][0]])
			{
				now = son[now][0];
				continue;
			}
			if (son[now][0])
				rnk -= size[son[now][0]];
			if (rnk == 1)
			{
				splay(now, rt);
				return now;
			}
			rnk -= 1;
			now = son[now][1];
		}
	}
	int queryrnk(int id)
	{
		int pos = hs[id];
		splay(pos, rt);
		return size[son[rt][0]] + 1;
	}
	void print(int x)
	{
		if (son[x][0])
			print(son[x][0]);
		printf("%d ", val[x]);
		if (son[x][1])
			print(son[x][1]);
	}
};
Splay sp;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	//a[1] = 0, a[n + 2] = n + 1;
	for (int i = 2; i <= n + 1; ++i)
		scanf("%d", &a[i]);
	sp.init();
	sp.rt = sp.build(0, 2, n + 1);
	char str[10];
	int x, y;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d", str, &x);
		if (str[0] == 'I')
		{
			scanf("%d", &y);
			sp.insert(x, y);
		}
		else if (str[0] == 'T')
			sp.Top_Bot(x, 0);
		else if (str[0] == 'B')
			sp.Top_Bot(x, 1);
		else if (str[0] == 'A')
			printf("%d\n", sp.queryrnk(x) - 1);
		else if (str[0] == 'Q')
			printf("%d\n", sp.val[sp.querynum(sp.rt, x)]);
		//sp.print(sp.rt);
		//printf("\n");
		
	}
	return 0;
}
