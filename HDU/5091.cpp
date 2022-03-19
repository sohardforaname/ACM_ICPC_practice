#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int b[MAXN << 1];
struct node
{
	int x, y1, y2, c;
	bool operator<(const node &a) const
	{
		return x < a.x;
	}
};
node s[MAXN];
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	struct node
	{
		int l, r, maxn, lazy;
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
		tr[k].maxn = tr[k].lazy = 0;
		if (l == r)
			return;
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
		pushup(k);
	}
	void update(int l, int r, int k, int v)
	{
		if (l <= tr[k].l && r >= tr[k].r)
		{
			tr[k].lazy += v;
			tr[k].maxn += v;
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
	while (scanf("%d", &n) && ~n)
	{
		int top = 0;
		scanf("%d%d", &w, &h);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d", &s[i].x, &s[i].y1), s[i].y2 = s[i].y1 + h;
			s[i + n] = s[i], s[i + n].x += w;
			s[i].c = 1, s[i + n].c = -1;
			b[++top] = s[i].y1, b[++top] = s[i].y1 + h;
		}
		sort(b + 1, b + top + 1);
		top = unique(b + 1, b + top + 1) - b - 1;
		for (int i = 1; i <= n * 2; ++i)
		{
			s[i].y1 = lower_bound(b + 1, b + top + 1, s[i].y1) - b;
			s[i].y2 = lower_bound(b + 1, b + top + 1, s[i].y2) - b;
		}
		sort(s + 1, s + n * 2 + 1);
		tr.build(1, top, 1);
		int ans = 0;
		for (int i = 1; i <= n * 2; ++i)
		{
			tr.update(s[i].y1, s[i].y2, 1, s[i].c);
			ans = max(ans, tr.tr[1].maxn);
		}
		printf("%d\n", ans);
	}
	return 0;
}