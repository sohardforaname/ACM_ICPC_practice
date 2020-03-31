#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 5;
char str[MAXN];
int pos;
struct Splay
{
	int fa[MAXN], son[MAXN][2], size[MAXN], val[MAXN];
	int rt, sz;
	void init()
	{
		sz = rt = 0;
	}
	void pushup(int x)
	{
		if (x)
		{
			size[x] = 1;
			if (son[x][0])
				size[x] += size[son[x][0]];//, pos[val[son[x][0]]] = son[x][0];
			if (son[x][1])
				size[x] += size[son[x][1]];//, pos[val[son[x][1]]] = son[x][1];
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
	void splay(int x,int end)
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
		pushup(x);
		if (!end)
			rt = x;
	}
	int newnode(int x, int f)
	{
		int root = ++sz;
		fa[root] = f;
		val[root] = x;
		son[root][0] = son[root][1] = 0;
		size[root] = 1;
		return root;
	}
	int build(int f, int l, int r)
	{
		if (l > r)
			return 0;
		int mid = (l + r) >> 1;
		int tmp = newnode(str[mid], f);
		son[tmp][0] = build(tmp, l, mid - 1);
		son[tmp][1] = build(tmp, mid + 1, r);
		pushup(tmp);
		return tmp;
	}
	int pre_nxt(int m)
	{
		int now = son[rt][m];
		while (son[now][m ^ 1])
			son[now][m ^ 1];
		return now;
	}
	int querynum(int x)
	{
		int now = rt;
		while (1)
		{
			if (!now)
				return 0;
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
		if (son[x][0])
			print(son[x][0]);
		if (val[x] >= 32 && val[x] <= 126)
			printf("%c", val[x]);
		if (son[x][1])
			print(son[x][1]);
	}
	//work
	void Move(int x)
	{
		pos = x + 1;
	}
	void Pre_Nxt(int x)
	{
		pos += x;
	}
	void Ins(int len, char* str)
	{
		int l = querynum(pos), r = querynum(pos + 1);
		splay(l, rt), splay(r, son[rt][1]);
		son[r][0] = build(r, 1, len);
		splay(r, rt);
	}
	void Del(int len)
	{
		int l = querynum(pos), r = querynum(pos + len + 1);
		splay(l, rt), splay(r, son[rt][1]);
		son[r][0] = 0;
		splay(r, rt);
	}
	void Get(int len)
	{
		int l = querynum(pos), r = querynum(pos + len + 1);
		splay(l, rt), splay(r, son[rt][1]);
		print(son[r][0]);
		putchar('\n');
	}
};
Splay sp;
char op[10], ch;
int main()
{
	sp.init();
	int n, x;
	scanf("%d", &n);
	pos = 1;
	str[1] = '\n', str[2] = '\n';
	sp.rt = sp.build(0, 1, 2);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", op);
		if (op[0] == 'I')
		{
			scanf("%d", &x);
			int j = 1;
			while (j <= x)
			{
				ch = getchar();
				if (ch >= 32 && ch <= 126)
					str[j++] = ch;
			}
			str[j] = 0;
			sp.Ins(x, str);
		}
		else if (op[0] == 'D')
			scanf("%d", &x), sp.Del(x);
		else if (op[0] == 'G')
			scanf("%d", &x), sp.Get(x);
		else if (op[0] == 'P')
			sp.Pre_Nxt(-1);
		else if (op[0] == 'N')
			sp.Pre_Nxt(1);
		else
			scanf("%d", &x), sp.Move(x);
		//sp.print(sp.rt);
		//putchar('\n');
	}
	return 0;
}