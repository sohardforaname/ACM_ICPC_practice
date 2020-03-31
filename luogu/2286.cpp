#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.2e5 + 5;
#define ll long long
struct Splay
{
	int rt, sz;
	int fa[MAXN], son[MAXN][2], size[MAXN], num[MAXN];
	ll val[MAXN];
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
	void con(int x, int y, int z)//x成为y的z儿子
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
	int newnode(ll x, int f)
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
		if (num[rt] > 1)
			return rt;
		int now = son[rt][0];
		while (son[now][1])
			now = son[now][1];
		splay(now, rt);
		return now;
	}
	int nxt()
	{
		if (num[rt] > 1)
			return rt;
		int now = son[rt][1];
		while (son[now][0])
			now = son[now][0];
		splay(now, rt);
		return now;
	}
	//public
	void clear(int x)
	{
		fa[x] = son[x][0] = son[x][1] = size[x] = num[x] = val[x] = 0;
	}
	void insert(ll x)
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
	int queryrnk(ll x)
	{
		int ans = 0, now = rt;
		while (1)
		{
			if (x < val[now])
			{
				now = son[now][0];
				continue;
			}
			ans += size[son[now][0]];
			if (x == val[now])
			{
				splay(now, rt);
				return ans + 1;
			}
			ans += num[now];
			now = son[now][1];
		}
	}
	void del(ll x)
	{
		queryrnk(x);
		if (num[rt] > 1)
		{
			--num[rt], up(rt);
			return;
		}
		else if (!son[rt][0] && !son[rt][1])
		{
			clear(rt), rt = 0;
			return;
		}
		else if (!son[rt][0])
		{
			int tmp = rt;
			rt = son[rt][1], fa[rt] = 0;
			clear(tmp);
			return;
		}
		else if (!son[rt][1])
		{
			int tmp = rt;
			rt = son[rt][0], fa[rt] = 0;
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
	ll queryfront(ll x)
	{
		insert(x);
		ll tmp = val[pre()];
		del(x);
		return tmp;
	}
	ll queryback(ll x)
	{
		insert(x);
		ll tmp = val[nxt()];
		del(x);
		return tmp;
	}
};
Splay sp;
int mod = 1000000;
int main()
{
	//freopen("D:\\in.txt", "r", stdin);
	//freopen("D:\\out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int c, val;
	sp.insert(1ll << 50);
	sp.insert((1ll << 50) * (-1));
	int cnt = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &c, &val);
		if (cnt == 0)
			sp.insert(val);
		else if (cnt > 0)
		{
			if (c == 0)
				sp.insert(val);
			else
			{
				ll ans1 = sp.queryfront(val), ans2 = sp.queryback(val);
				if (abs(val - ans1) <= abs(val - ans2))
				{
					sp.del(ans1);
					ans = (ans + abs(val - ans1)) % mod;
				}
				else if (abs(val - ans1) > abs(val - ans2))
				{
					sp.del(ans2);
					ans = (ans + abs(val - ans2)) % mod;
				}
			}
		}
		else if (cnt < 0)
		{
			if (c == 1)
				sp.insert(val);
			else
			{
				ll ans1 = sp.queryfront(val), ans2 = sp.queryback(val);
				if (abs(val - ans1) <= abs(val - ans2))
				{
					sp.del(ans1);
					ans = (ans + abs(val - ans1)) % mod;
				}
				else if (abs(val - ans1) > abs(val - ans2))
				{
					sp.del(ans2);
					ans = (ans + abs(val - ans2)) % mod;
				}
			}
		}
		cnt += c ? -1 : 1;
	}
	printf("%lld\n", ans);
	return 0;
}
