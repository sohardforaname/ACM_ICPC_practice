#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node
{
	int w, c;
	bool operator==(const node& a)const
	{
		return c == a.c;
	}
	node(int _w, int _c)
	{
		w = _w;
		c = _c;
	}
	node() { w = 0; c = 0; }
};
struct Splay
{
	node val[MAXN];
	int fa[MAXN], size[MAXN], num[MAXN], son[MAXN][2];
	int rt, sz;
	void init()
	{
		rt = sz = 0;
	}
	int getson(int x)
	{
		return son[fa[x]][1] == x;
	}
	void clear(int x)
	{
		fa[x] = size[x] = num[x] = son[x][0] = son[x][1] = 0;
	}
	bool cmp(node& a, node& b)
	{
		if (a.c < b.c)
			return 0;
		else if (a.c > b.c)
			return 1;
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
		int fs = getson(x), ffs = getson(fx);
		con(son[x][fs ^ 1], fx, fs);
		con(fx, x, fs ^ 1);
		con(x, ffx, ffs);
		up(fx);
		up(x);
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
	int newnode(node& a, int f)
	{
		int root = ++sz;
		fa[root] = f;
		son[f][cmp(a, val[f])] = root;
		size[root] = num[root] = 1;
		son[root][0] = son[root][1] = 0;
		val[root] = a;
		return root;
	}
	void insert(node& a)
	{
		if (!rt)
		{
			rt = newnode(a, 0);
			return;
		}
		int now = rt, f = 0;
		while (1)
		{
			if (a == val[now])
			{
				++num[now];
				up(now);
				up(f);
				splay(now, rt);
				return;
			}
			f = now, now = son[now][cmp(a, val[now])];
			if (!now)
			{
				int tmp = newnode(a, f);
				up(f);
				splay(tmp, rt);
				return;
			}
		}
	}
	int pre()
	{
		int now = son[rt][0];
		while (son[now][1])
			now = son[now][1];
		return now;
	}
	int querynum(int rnk)
	{
		int now = rt;
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
			if (rnk <= num[now])
			{
				splay(now, rt);
				return now;
			}
			rnk -= num[now];
			now = son[now][1];
		}
	}
	int queryrnk(node x)
	{
		int ans = 0, now = rt;
		while (1)
		{
			if (!now)
				return 0;
			if (x == val[now])
			{
				splay(now, rt);
				return ans + size[son[now][0]] + 1;
			}
			if (!cmp(x, val[now]))
			{
				now = son[now][0];
				continue;
			}
			ans += size[son[now][0]];
			ans += num[now];
			now = son[now][1];
		}
	}
	void del(node& a)
	{
		queryrnk(a);
		if (num[rt] > 1)
		{
			--num[rt];
			up(rt);
			return;
		}
		else if (!son[rt][0] && !son[rt][1])
		{
			clear(rt);
			rt = 0;
			return;
		}
		else if (!son[rt][0])
		{
			int tmp = rt;
			rt = son[rt][1];
			fa[rt] = 0;
			clear(tmp);
			return;
		}
		else if (!son[rt][1])
		{
			int tmp = rt;
			rt = son[rt][0];
			fa[rt] = 0;
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
	pair<long long, long long> cal(int x)
	{
		pair<long long, long long>ans = { 0,0 }, tmp;
		if (son[x][0])
		{
			tmp = cal(son[x][0]);
			ans.first += tmp.first;
			ans.second += tmp.second;
		}
		ans.first += val[x].w, ans.second += val[x].c;
		//printf("%d %d\n", val[x].w, val[x].c);
		if (son[x][1])
		{
			tmp = cal(son[x][1]);
			ans.first += tmp.first;
			ans.second += tmp.second;
		}
		return ans;
	}
};
Splay sp;
int main()
{
	//freopen("D:\\out.txt", "w", stdout);
	int op, w, c;
	int cnt = 0;
	while (scanf("%d", &op) && op != -1)
	{
		if (op == 1)
		{
			scanf("%d%d", &w, &c);
			node tmp = node(w, c);
			if (!sp.queryrnk(tmp))
				sp.insert(tmp), ++cnt;
		}
		else if (op == 2 && cnt)
		{
			int pos = sp.querynum(cnt);
			if (pos)
				sp.del(sp.val[pos]), --cnt;
		}
		else if (op == 3 && cnt)
		{
			int pos = sp.querynum(1);
			if (pos)
				sp.del(sp.val[pos]), --cnt;
		}
	}
	auto ans = sp.cal(sp.rt);
	printf("%lld %lld\n", ans.first, ans.second);
	return 0;
}
