#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node
{
	int val, pos;
	node() {};
	node(int _val, int _pos) :val(_val), pos(_pos) {};
};
node a[MAXN];
bool cmp(node& a, node& b)
{
	return a.val < b.val || (a.val == b.val && a.pos < b.pos);
}
int hs[MAXN];
struct Splay
{
	int fa[MAXN], son[MAXN][2], val[MAXN], size[MAXN];
	int tag[MAXN];
	int rt, sz;
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
		fa[root] = f;
		son[root][0] = son[root][1] = 0;
		size[root] = 1;
		tag[root] = 0;
		val[root] = x;
		return root;
	}
	int build(int f, int l, int r)
	{
		if (l > r)
			return 0;
		int m = (l + r) >> 1;
		int tmp = newnode(a[m].val, f);
		hs[a[m].pos] = tmp;
		son[tmp][0] = build(tmp, l, m - 1);
		son[tmp][1] = build(tmp, m + 1, r);
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
		int l = querynum(ql - 1), r = querynum(qr + 1);
		splay(l, rt), splay(r, son[l][1]);
		tag[son[r][0]] ^= 1;
	}
	void solve(int i, int pos)
	{
		int trp = hs[pos];
		splay(trp, rt);
		int rnk = size[son[rt][0]];
		printf("%d ", rnk);
		reverse(i, rnk + 1);
	}
	void init()
	{
		rt = sz = 0;
	}
};
Splay sp;
int main()
{
	int n;
	scanf("%d", &n);
	a[1] = node(0, 1);
	a[n + 2] = node(1e7 + 5, n + 2);
	for (int i = 2; i <= n + 1; ++i)
		scanf("%d", &a[i].val), a[i].pos = i;
	sp.init();
	sp.rt = sp.build(0, 1, n + 2);
	sort(a + 1, a + n + 3, cmp);
	for (int i = 2; i <= n + 1; ++i)
		sp.solve(i, a[i].pos);
	printf("\n");
	return 0;
}