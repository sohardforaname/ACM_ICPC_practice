#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node
{
	int y1, y2, k;
	double x1;
	bool operator<(const node& a)const
	{
		return x1 < a.x1;
	}
};
double b[MAXN << 1];
double y_1[MAXN], y_2[MAXN];
node tp[MAXN];
int n;
struct segtree
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
	double len[MAXN << 2];
	int l[MAXN << 2], r[MAXN << 2], cnt[MAXN << 2];
	void pushup(int k)
	{
		if (cnt[k])
			len[k] = b[r[k] + 1] - b[l[k]];
		else
			len[k] = len[ls] + len[rs];
	}
	void build(int ql, int qr, int k)
	{
		l[k] = ql, r[k] = qr;
		cnt[k] = len[k] = 0;
		if (ql == qr)
			return;
		int m = (ql + qr) >> 1;
		build(ql, m, ls);
		build(m + 1, qr, rs);
		pushup(k);
	}
	void update(int ql, int qr, int val, int k)
	{
		if (ql <= l[k] && qr >= r[k])
		{
			cnt[k] += val;
			pushup(k);
			return;
		}
		int m = (l[k] + r[k]) >> 1;
		if (ql <= m)
			update(ql, qr, val, ls);
		if (qr > m)
			update(ql, qr, val, rs);
		pushup(k);
	}
};
segtree tr;
int main()
{	
	int cas = 1;
	while (scanf("%d", &n) && n)
	{
		int top = 0, btop = 0;
		double x_1, x_2;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lf%lf%lf%lf", &x_1, &y_1[i], &x_2, &y_2[i]);
			tp[++top].x1 = x_1, tp[top].k = 1;
			tp[++top].x1 = x_2, tp[top].k = -1;
			b[++btop] = y_1[i], b[++btop] = y_2[i];
		}
		sort(b + 1, b + btop + 1);
		btop = unique(b + 1, b + btop + 1) - b - 1;
		tr.build(1, btop - 1, 1);
		for (int i = 1; i <= n; ++i)
		{
			tp[i * 2 - 1].y1 = lower_bound(b + 1, b + btop + 1, y_1[i]) - b;
			tp[i * 2 - 1].y2 = lower_bound(b + 1, b + btop + 1, y_2[i]) - b;
			tp[i * 2].y1 = tp[i * 2 - 1].y1;
			tp[i * 2].y2 = tp[i * 2 - 1].y2;
		}
		sort(tp + 1, tp + top + 1);
		double ans = 0;
		tr.update(tp[1].y1, tp[1].y2 - 1, tp[1].k, 1);
		for (int i = 2; i <= top; ++i)
		{
			ans += tr.len[1] * (tp[i].x1 - tp[i - 1].x1);
			tr.update(tp[i].y1, tp[i].y2 - 1, tp[i].k, 1);
		}
		//printf("%.2f\n", ans);
		printf("Test case #%d\nTotal explored area: ", cas++);
		printf("%.2f\n\n", ans);
	}
	return 0;
}