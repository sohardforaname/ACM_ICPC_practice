#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#pragma GCC optimize(2)
using namespace std;
struct Point
{
	int x, y;
	bool operator<(const Point& a)const
	{
		return y == a.y ? x<a.x : y>a.y;
	}
};
Point p[200005];
int x[200005], y[2000005];
struct Segtree
{
	struct node
	{
		int l, r;
		int v;
	}tr[200005 * 4];
	void build(int l, int r, int k)
	{
		tr[k].l = l, tr[k].r = r;
		if (l == r)
		{
			tr[k].v = 0;
			return;
		}
		int m = (l + r) / 2;
		build(l, m, k * 2);
		build(m + 1, r, k * 2 + 1);
		tr[k].v = tr[k * 2].v + tr[k * 2 + 1].v;
	}
	void update(int pos, int k, int val)
	{
		if (tr[k].l == tr[k].r)
		{
			tr[k].v = val;
			return;
		}
		int m = (tr[k].l + tr[k].r) / 2;
		if (pos <= m)
			update(pos, k * 2, val);
		else if (pos > m)
			update(pos, k * 2 + 1, val);
		tr[k].v = tr[k * 2].v + tr[k * 2 + 1].v;
	}
	int query(int l, int r, int k)
	{
		if (l > r)
			return 0;
		if (l <= tr[k].l && r >= tr[k].r)
		{
			return tr[k].v;
		}
		int m = (tr[k].l + tr[k].r) / 2;
		//cout<<tr[k].l<<" "<<tr[k].r<<endl;
		int ans = 0;
		if (l <= m)
			ans += query(l, r, k * 2);
		if (r > m)
			ans += query(l, r, k * 2 + 1);
		return ans;
	}
};
Segtree seg;
int ydiv[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
		p[i].x = x[i];
		p[i].y = y[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	int xnew = unique(x, x + n) - x;
	int ynew = unique(y, y + n) - y;
	for (int i = 0; i < n; ++i)
	{
		p[i].x = lower_bound(x, x + xnew, p[i].x) - x + 1;
		p[i].y = lower_bound(y, y + ynew, p[i].y) - y + 1;
		//cout<<p[i].x<<" "<<p[i].y<<endl;
	}
	sort(p, p + n);
	//ɨ����
	seg.build(1, xnew + 1, 1);
	int beg = 0, cur = 0;
	long long sum = 0;
	while (beg < n)
	{
		int pos = 0;
		while (cur < n && p[cur].y == p[beg].y)
		{
			seg.update(p[cur].x, 1, 1);
			ydiv[pos++] = p[cur++].x;
		}
		ydiv[pos] = xnew + 1;
		for (int i = 0; i < pos; ++i)
		{
			long long cntl = seg.query(1, ydiv[i] - 1, 1);
			long long cntr = seg.query(ydiv[i] + 1, ydiv[i + 1] - 1, 1);
			sum += (cntl + 1) * (cntr + 1);
		}
		beg = cur;
	}
	cout << sum << endl;
	return 0;
}
