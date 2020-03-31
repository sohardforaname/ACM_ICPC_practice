#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e5 + 5;
int id[MAXN];
struct Splay
{
	struct node
	{
		int v, rnk;
		node(int _v, int _rnk) :v(_v), rnk(_rnk) {};
		node(){}
	};
	node val[MAXN];
	int fa[MAXN], son[MAXN][2], size[MAXN];
	int num[MAXN];
	int sz, rt;
	bool cmp(node& a, node& b)
	{
		return a.rnk >= b.rnk;
	}
	void swp(node& a, node& b)
	{
		int tmp = a.rnk;
		a.rnk = b.rnk;
		b.rnk = tmp;
	}
	void pushup(int x)
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
	int getson(int x)
	{
		return son[fa[x]][1] == x;
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
				rotate(getson(x) == getson(f) ? f : x);
			rotate(x);
		}
		if (!end)
			rt = x;
	}
	void clear(int x)
	{
		val[0].v = son[x][0] = son[x][1] = 0;
		fa[x] = num[x] = size[x] = 0;
		val[0].rnk = 0;
	}
	int newnode(node x, int f)
	{
		int root = ++sz;
		fa[root] = f;
		son[f][cmp(x, val[f])] = root;
		val[root] = x;
		son[root][0] = son[root][1] = 0;
		num[root] = size[root] = 1;
		return root;
	}
	void insert(node x)
	{
		if (!rt)
		{
			rt = newnode(x, 0);
			return;
		}
		int now = rt, f = 0;
		while (1)
		{
			if (x.rnk == val[now].rnk)
			{
				++num[now];
				pushup(now), pushup(f);
				splay(now, rt);
				return;
			}
			f = now, now = son[now][cmp(x, val[now])];
			if(!now)
			{
				int tmp = newnode(x, f);
				pushup(f);
				splay(tmp, rt);
				return;
			}
		}
	}
	void del(int x)
	{
		queryrnk(x);
		if (num[rt] > 1)
		{
			--num[rt], pushup(rt);
			return;
		}
		else if (!son[rt][0] || !son[rt][1])
		{
			int tmp = rt;
			rt = son[rt][0] + son[rt][1];
			fa[rt] = 0;
			clear(rt);
			return;
		}
		else
		{
			int tmp = rt, l = pre();
			splay(l, rt);
			con(son[tmp][1], rt, 1);
			clear(tmp);
			pushup(rt);
			return;
		}
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
	node querynum(int rnk)
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
	int queryrnk(int x)
	{
		int now = rt, ans = 0;
		while (val[now].rnk != x)
		{
			if (!now)
				return -0x3f3f3f3f;
			if (val[now].rnk < x)
				now = son[now][1];
			else if (val[now].rnk > x)
				now = son[now][0];
		}
		splay(now, rt);
		return size[son[rt][0]];
	}
	// work
	void top_bottom(int x, int y)//x为旧id,y为新id
	{
		queryrnk(x);
		auto tmp = val[rt];
		tmp.rnk = y;
		del(x);
		insert(tmp);
	}
	void ins(int x, int mod)//x为id
	{
		if (mod)
		{
			queryrnk(x);
			auto v1 = val[mod == -1 ? pre() : nxt()], v2 = val[rt];
			id[v1.v] = v2.rnk, id[v2.v] = v1.rnk;
			del(v2.rnk), del(v1.rnk);
			swp(v1, v2);
			insert(v1), insert(v2);
		}
	}
	void init()
	{
		rt = sz = 0;
	}
};
Splay sp;
typedef Splay::node nd;
int main()
{
	int n, m, a, b;
	
	scanf("%d%d", &n, &m);
	sp.init();
	sp.insert(nd(-0x3f3f3f3f, -0x3f3f3f3f));
	sp.insert(nd(0x3f3f3f3f, 0x3f3f3f3f));
	int head = 1, tail = n;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		sp.insert(nd(a, i));
		id[a] = i;
	}
	char str[10];
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s%d", str, &a);
		if (str[0] == 'I')
		{
			scanf("%d", &b);
			sp.ins(id[a], b);
		}
		else if (str[0] == 'T')
		{
			int tmp = id[a];
			id[a] = --head;
			sp.top_bottom(tmp, id[a]);
		}
		else if (str[0] == 'B')
		{
			int tmp = id[a];
			id[a] = ++tail;
			sp.top_bottom(tmp, id[a]);
		}
		else if (str[0] == 'A')
			printf("%d\n", sp.queryrnk(id[a]) - 1);
		else if (str[0] == 'Q')
			printf("%d\n", sp.querynum(a + 1).v);
	}
	return 0;
}