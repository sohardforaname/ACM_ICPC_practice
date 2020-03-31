#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 5;
struct node
{
	int x, y, c;
	bool operator<(const node &a) const
	{
		return x == a.x ? y < a.y : x < a.x;
	}
};
node p[MAXN];
int b[MAXN << 1];
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	struct node
	{
		int l, r;
		ll sum, lmax, rmax, tmax;
	};
	node tr[MAXN << 2];
	void pushup(int k)
	{
		tr[k].sum = tr[ls].sum + tr[rs].sum;
		tr[k].lmax = max(tr[ls].lmax, tr[ls].sum + tr[rs].lmax);
		tr[k].rmax = max(tr[rs].rmax, tr[rs].sum + tr[ls].rmax);
		tr[k].tmax = max(tr[ls].rmax + tr[rs].lmax, max(tr[ls].tmax, tr[rs].tmax));
	}
	void build(int l, int r, int k)
	{
		tr[k].l = l, tr[k].r = r;
		tr[k].sum = tr[k].lmax = tr[k].rmax = tr[k].tmax = 0;
		if (l == r)
			return;
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		pushup(k);
	}
	void update(int pos, int val, int k)
	{
		if (tr[k].l == tr[k].r)
		{
			tr[k].sum = tr[k].lmax = tr[k].rmax = tr[k].tmax += val;
			return;
		}
		int m = (tr[k].l + tr[k].r) >> 1;
		if (pos <= m)
			update(pos, val, ls);
		else if (pos > m)
			update(pos, val, rs);
		pushup(k);
	}
	ll query()
	{
		return tr[1].tmax;
	}
};
segtree tr;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, top = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
			b[++top] = p[i].x, b[++top] = p[i].y;
		}
		sort(b + 1, b + top + 1);
		top = unique(b + 1, b + top + 1) - b - 1;
		for (int i = 1; i <= n; ++i)
		{
			p[i].x = lower_bound(b + 1, b + top + 1, p[i].x) - b;
			p[i].y = lower_bound(b + 1, b + top + 1, p[i].y) - b;
		}
		ll ans = 0;
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; ++i)
		{
			if (i != 1 && p[i].x == p[i - 1].x) //跳出时i位于新的一列
				continue;
			tr.build(1, top, 1);
			for (int j = i; j <= n; ++j)
			{
				if (j != i && p[j].x != p[j - 1].x) //进入时重启一行
					ans = max(ans, tr.query());
				tr.update(p[j].y, p[j].c, 1);
			}
			ans = max(ans, tr.query());
		}
		printf("%lld\n", ans);
	}
	return 0;
}
