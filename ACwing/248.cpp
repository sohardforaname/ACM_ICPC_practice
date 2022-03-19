#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int b[MAXN << 1];
struct star
{
	int x, y;
	ll c;
};
star st[MAXN];
struct seg
{
	int x, y1, y2;
	ll c;
	bool operator<(const seg& a)const
	{
		return x < a.x;
	}
};
seg s[MAXN << 1];
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	struct node
	{
		int l, r;
		ll lazy, maxn;
	};
	node tr[MAXN << 3];
	void pushup(int k)
	{
		tr[k].maxn = max(tr[ls].maxn, tr[rs].maxn);
	}
	void pushdown(int k)
	{
		if (tr[k].lazy)
		{
			tr[ls].lazy += tr[k].lazy;
			tr[rs].lazy += tr[k].lazy;
			tr[ls].maxn += tr[k].lazy;
			tr[rs].maxn += tr[k].lazy;
			tr[k].lazy = 0;
		}
	}
	void build(int l, int r, int k)
	{
		tr[k].l = l, tr[k].r = r;
		tr[k].lazy = tr[k].maxn = 0;
		if (l == r)
			return;
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		pushup(k);
	}
	void update(int l, int r, int k, ll v)
	{
		if (l <= tr[k].l && r >= tr[k].r)
		{
			tr[k].maxn += v;
			tr[k].lazy += v;
			return;
		}
		pushdown(k);
		int m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			update(l, r, ls, v);
		if (r > m)
			update(l, r, rs, v);
		pushup(k);
	}
};
segtree tr;
int main()
{
	int n, w, h;
	while (~scanf("%d%d%d", &n, &w, &h))
	{
		int top = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d%lld", &st[i].x, &st[i].y, &st[i].c);
			b[++top] = st[i].y, b[++top] = st[i].y + h - 1;
			s[i].x = st[i].x, s[i + n].x = st[i].x + w - 1;
		}
		sort(b, b + top + 1);
		top = unique(b + 1, b + top + 1) - b - 1;
		for (int i = 1; i <= n; ++i)
		{
			s[i].y1 = lower_bound(b + 1, b + top + 1, st[i].y) - b;
			s[i].y2 = lower_bound(b + 1, b + top + 1, st[i].y + h - 1) - b;
			s[i + n].y1 = s[i].y1, s[i + n].y2 = s[i].y2;
			s[i].c = st[i].c, s[i + n].c = -st[i].c;
		}
		sort(s + 1, s + n * 2 + 1);
		tr.build(1, top, 1);
		ll ans = 0;
		for (int i = 1; i <= n * 2; ++i)
		{
			tr.update(s[i].y1, s[i].y2, 1, s[i].c);
			ans = max(ans, tr.tr[1].maxn);
		}
		printf("%lld\n", ans);
	}
	return 0;
}