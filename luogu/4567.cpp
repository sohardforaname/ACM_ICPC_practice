#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 5;
int pos;
int a[MAXN];
struct Splay
{
	int fa[MAXN], son[MAXN][2], val[MAXN], size[MAXN];
	bool tag[MAXN];
	int rt, sz;
	void init()
	{
		rt = sz = 0;
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
	void rotate(int x)
	{
		int fx = fa[x], ffx = fa[fx];
		int fs = getson(x), ffs = getson(fx);
		con(son[x][fs ^ 1], fx, fs);
		con(fx, x, fs ^ 1);
		con(x, ffx, ffs);
		pushup(fx);
	}
	void splay(int x, int end)
	{
		end = fa[end];
		int f;
		while (fa[x] != end)
		{
			f = fa[x];
			pushdown(fa[f]), pushdown(f), pushdown(x);
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
		val[root] = x;
		size[root] = 1;
		tag[root] = 0;
		fa[root] = f;
		son[root][0] = son[root][1] = 0;
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
		pushup(tmp);
		return tmp;
	}
	int querynum(int x)
	{
		int now = rt;
		while (1)
		{
			if (!now)
				return 0;
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
	}
	void print(int x)
	{
		pushdown(x);
		if (son[x][0])
			print(son[x][0]);
		printf("%d ", val[x]);
		if (son[x][1])
			print(son[x][1]);
	}
	//work
	void Pre_Nxt(int m)
	{
		pos += m;
	}
	void Mov(int m)
	{
		pos = m + 1;
	}
	void Ins(int len)
	{
		int l = querynum(pos), r = querynum(pos + 1);
		splay(l, rt), splay(r, son[l][1]);
		getchar();
		int j = 1;
		while (j <= len)
			a[j++] = getchar();
		son[r][0] = build(r, 1, len);
		splay(r, rt);
	}
	void Del(int len)
	{
		int l = querynum(pos), r = querynum(pos + len + 1);
		splay(l, rt), splay(r, son[l][1]);
		son[r][0] = 0;
		splay(r, rt);
	}
	void Rot(int len)
	{
		int l = querynum(pos), r = querynum(pos + len + 1);
		splay(l, rt), splay(r, son[l][1]);
		tag[son[r][0]] ^= 1;
		splay(r, rt);
	}
	void Get()
	{
		int l = querynum(pos), r = querynum(pos + 2);
		splay(l, rt), splay(r, son[l][1]);
		//assert(val[son[r][0]] != '\n');
		if (val[son[r][0]] != '\n')
			printf("%c", val[son[r][0]]);
		putchar('\n');
	}
};
Splay sp;
int main()
{
	int n;
	sp.init();
	pos = 1;
	a[1] = a[2] = '\n';
	sp.rt = sp.build(0, 1, 2);
	scanf("%d", &n);
	char op[10];
	int len;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", op);
		if (op[0] == 'M')
			scanf("%d", &len), sp.Mov(len);
		else if (op[0] == 'I')
		{
			scanf("%d", &len);
			sp.Ins(len);
		}
		else if (op[0] == 'D')
			scanf("%d", &len), sp.Del(len);
		else if (op[0] == 'R')
			scanf("%d", &len), sp.Rot(len);
		else if (op[0] == 'P' || op[0] == 'N')
			sp.Pre_Nxt(op[0] == 'P' ? -1 : 1);
		else if (op[0] == 'G')
			sp.Get();
		//sp.print(sp.rt);
		//printf("\n");
	}
	return 0;
}