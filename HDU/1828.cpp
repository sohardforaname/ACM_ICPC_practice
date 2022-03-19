#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e3 + 5;
int b[2][MAXN << 1];
struct seg
{
	int x, y1, y2, c;
	seg() {}
	seg(int _x, int _y1, int _y2, int _c) :x(_x), y1(_y1), y2(_y2), c(_c) {}
	bool operator<(const seg& a)const
	{
		return x < a.x;
	}
};
int p = 0;
seg s[2][MAXN << 1];
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	struct node
	{
		int l, r, len, cnt;
	};
	node tr[MAXN << 3];
	void pushup(int k)
	{
		if (tr[k].cnt)
			tr[k].len = b[p][tr[k].r + 1] - b[p][tr[k].l];
		else
			tr[k].len = tr[ls].len + tr[rs].len;
	}
	void build(int l, int r, int k)
	{
		tr[k].cnt = tr[k].len = 0;
		tr[k].l = l, tr[k].r = r;
		if (l == r)
			return;
		int m = (l + r) >> 1;
		build(l, m, ls);
		build(m + 1, r, rs);
	}
	void update(int l, int r, int k, int val)
	{
		if (l <= tr[k].l && r >= tr[k].r)
		{
			tr[k].cnt += val;
			pushup(k);
			return;
		}
		int m = (tr[k].l + tr[k].r) >> 1;
		if (l <= m)
			update(l, r, ls, val);
		if (r > m)
			update(l, r, rs, val);
		pushup(k);
	}
	int query()
	{
		return tr[1].len;
	}
};
segtree tr;
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int top[2] = { 0 ,0 };
		int x_1, x_2, y_1, y_2;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
			s[1][i] = seg(x_1, y_1, y_2, 1);
			s[1][i + n] = seg(x_2, y_1, y_2, -1);
			s[0][i] = seg(y_1, x_1, x_2, 1);
			s[0][i + n] = seg(y_2, x_1, x_2, -1);
			b[0][++top[0]] = x_1, b[1][++top[1]] = y_1, b[0][++top[0]] = x_2, b[1][++top[1]] = y_2;
		}
		sort(b[0] + 1, b[0] + top[0] + 1);
		sort(b[1] + 1, b[1] + top[1] + 1);
		top[0] = unique(b[0] + 1, b[0] + top[0] + 1) - b[0] - 1;
		top[1] = unique(b[1] + 1, b[1] + top[1] + 1) - b[1] - 1;
		sort(s[0] + 1, s[0] + n * 2 + 1);
		sort(s[1] + 1, s[1] + n * 2 + 1);
		ll ans = 0;
		for (int i = 0; i < 2; ++i)
		{
			p = i;
			tr.build(1, top[i] - 1, 1);
			int l, r, lst = 0;
			for (int j = 1; j <= n * 2; ++j)
			{
				l = lower_bound(b[i] + 1, b[i] + top[i] + 1, s[i][j].y1) - b[i];
				r = lower_bound(b[i] + 1, b[i] + top[i] + 1, s[i][j].y2) - b[i];
				tr.update(l, r - 1, 1, s[i][j].c);
				ans += abs(tr.query() - lst);
				lst = tr.query();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}