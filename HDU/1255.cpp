#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
struct seg
{
	double x;
	int y1, y2, c;
	seg() {}
	seg(double _x, int _y1, int _y2, int _c) :x(_x), y1(_y1), y2(_y2), c(_c) {}
	bool operator<(const seg& a)const
	{
		return x < a.x;
	}
};
seg s[MAXN << 1];
double b[MAXN << 1], px[MAXN << 1], py[MAXN << 1];
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	struct node
	{
		int l, r, cnt;
		double one, two;
	};
	node tr[MAXN << 3];
	void pushup(int k)
	{
		if (tr[k].cnt >= 2)
		{
			tr[k].two = b[tr[k].r + 1] - b[tr[k].l];
			tr[k].one = b[tr[k].r + 1] - b[tr[k].l];
		}
		else if (tr[k].cnt == 1)
		{
			tr[k].two = tr[ls].one + tr[rs].one;
			tr[k].one = b[tr[k].r + 1] - b[tr[k].l];
		}
		else
		{
			tr[k].two = tr[ls].two + tr[rs].two;
			tr[k].one = tr[ls].one + tr[rs].one;
		}
	}
	void build(int l, int r, int k)
	{
		tr[k].l = l, tr[k].r = r;
		tr[k].cnt = tr[k].one = tr[k].two = 0;
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
			tr[k].cnt += v;
			pushup(k);
			return;
		}
		int m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			update(l, r, ls, v);
		if (r > m)
			update(l, r, rs, v);
		pushup(k);
	}
	double query()
	{
		return tr[1].two;
	}
};
segtree tr;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int top = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lf%lf%lf%lf", &px[i], &py[i], &px[i + n], &py[i + n]);
			b[++top] = py[i], b[++top] = py[i + n];
		}
		sort(b + 1, b + top + 1);
		top = unique(b + 1, b + top + 1) - b - 1;
		for (int i = 1; i <= n; ++i)
		{
			int l = lower_bound(b + 1, b + top + 1, py[i]) - b;
			int r = lower_bound(b + 1, b + top + 1, py[i + n]) - b;
			s[i] = seg(px[i], l, r, 1);
			s[i + n] = seg(px[i + n], l, r, -1);
		}
		sort(s + 1, s + n * 2 + 1);
		tr.build(1, top - 1, 1);
		tr.update(s[1].y1, s[1].y2 - 1, 1, s[1].c);
		double ans = 0;
		for (int i = 2; i <= n * 2; ++i)
		{
			ans += tr.query() * (s[i].x - s[i - 1].x);
			tr.update(s[i].y1, s[i].y2 - 1, 1, s[i].c);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}