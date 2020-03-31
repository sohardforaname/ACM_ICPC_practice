#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Splay
{
	int rt, sz;
	int fa[MAXN], son[MAXN][2], size[MAXN], num[MAXN], val[MAXN];
	//private
	int getson(int x)
	{
		return son[fa[x]][1] == x;
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
		int ffs = getson(fx), fs = getson(x);
		con(son[x][fs ^ 1], fx, fs);
		con(fx, x, fs ^ 1);
		con(x, ffx, ffs);
		up(fx);
	}
	void splay(int x, int end)
	{
		end = fa[end];
		int f;
		while(fa[x] != end)
		{
			f = fa[x];
			if (fa[f] != end)
				rotate(getson(x) == getson(f) ? f : x);
			rotate(x);
		}
		up(x);
		if(!end)
			rt = x;
	}
	int newnode(int x, int f)
	{
		int nrt = ++sz;
		val[nrt] = x;
		fa[nrt] = f;
		son[f][x > val[f]] = nrt;
		size[nrt] = num[nrt] = 1;
		son[nrt][0] = son[nrt][1] = 0;
		return nrt;
	}
	int pre()
	{
		int now = son[rt][0];
		while (son[now][1])
			now = son[now][1];
		return now;
	}
	int nxt()
	{
		int now = son[rt][1];
		while (son[now][0])
			now = son[now][0];
		return now;
	}
	//public
	void clear(int x)
	{
		fa[x] = son[x][0] = son[x][1] = size[x] = num[x] = val[x] = 0;
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
			f = now;
			now = son[now][x > val[now]];
			if (!now)
			{
				int tmp = newnode(x, f);
				up(f);
				splay(tmp, rt);
				return;
			}
		}
	}
	int queryrnk(int x)
	{
		int now = rt, ans = 0;
		while (val[now] != x)
		{
			if (!now)
				return 0;
			if (val[now] < x)
				now = son[now][1];
			else if (val[now] > x)
				now = son[now][0];
		}
		splay(now, rt);
		return size[son[rt][0]] + 1;
	}
	int querynum(int rnk)
	{
		int now = rt;
		while (1)
		{
			if (son[now][0] && rnk <= size[son[now][0]])
			{
				now = son[now][0];
				continue;
			}
			if (son[now][0])
				rnk -= size[son[now][0]];
			if (rnk <= num[now])
			{
				splay(now, rt);
				return val[now];
			}
			rnk -= num[now];
			now = son[now][1];
		}
	}
	void del(int x)
	{
		queryrnk(x);
		if (num[rt] > 1)
		{
			--num[rt], up(rt);
			return;
		}
		else if (!son[rt][0] || !son[rt][1])
		{
			int tmp = rt;
			rt = son[rt][1] + son[rt][0], fa[rt] = 0;
			clear(tmp);
			return;
		}
		else
		{
			int tmp = rt, l = pre();
			splay(l, rt);
			con(son[tmp][1], rt, 1);
			clear(tmp);
			up(rt);
			return;
		}
	}
	int queryfront(int x)
	{
		insert(x);
		int tmp = val[pre()];
		del(x);
		return tmp;
	}
	int queryback(int x)
	{
		insert(x);
		int tmp = val[nxt()];
		del(x);
		return tmp;
	}
};
Splay sp;
int main()
{
	int n;
	scanf("%d", &n);
	int op, x;
	sp.clear(0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &op, &x);
		if (op == 1)
			sp.insert(x);
		else if (op == 2)
			sp.del(x);
		else if (op == 3)
			printf("%d\n", sp.queryrnk(x));
		else if (op == 4)
			printf("%d\n", sp.querynum(x));
		else if (op == 5)
			printf("%d\n", sp.queryfront(x));
		else if (op == 6)
			printf("%d\n", sp.queryback(x));
	}
	return 0;
}
